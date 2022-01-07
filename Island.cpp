#include "Island.h"

Island::Island(){

}

Island::~Island() {
    for (auto &i : zone) {
        delete i;
    }
}

Island* Island::Create(int cols, int rows) {
    auto* map = new Island;
    map->cols = cols;
    map->rows = rows;
    for (int i = 0; i < cols * rows; ++i) {
        map->zone.push_back(Cell::Create());
        //map->zone.at(i)->id = i;
    }

    return map;
}

string Island::PrintIsland() {
    ostringstream oss;

    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i)
            oss << " -----------------";
        oss << endl;

        /*for (int i = 0; i < cols; ++i)
            oss << "|ID:" << zone.at(j * rows + i)->id << "             ";
        oss << '|' << endl;*/

        for (int i = 0; i < cols; ++i)
            oss << "|Bioma:" << zone.at(j * rows + i)->GetType();
        oss << '|' << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Ed.:" << zone.at(j * rows + i)->GetBuildingType();
        oss << '|' << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Trab.:" << zone.at(j * rows + i)->GetWorkersString();
        oss << '|' << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Total:" << zone.at(j * rows + i)->GetWorkerCount();
        oss << '|' << endl;
    }

    for (int i = 0; i < cols; ++i)
        oss << " -----------------";

    oss << endl;

    return oss.str();
}

int Island::GetCols() const {
    return cols;
}

int Island::GetRows() const {
    return rows;
}

string Island::GetZonesSaveData() const{
    ostringstream oss;

    oss << "start_zone_info\n";
    for (int z = 0; z < zone.size(); ++z) {
        oss << "i-" << z << "\n";
        oss << "b-" << zone[z]->GetType() << "\n";
        oss << "e-" << zone[z]->GetBuildingType() << "\n";
        oss << "n-" << zone[z]->GetBuilding()->GetLevel() << "\n";
        oss << "t" << zone[z]->GetWorkerCount() << "\n";

        oss << "start-trabalhadores\n";
        for (auto & worker : zone[z]->GetWorkerList()) {
            oss << "id-" << worker->GetID() << "\n";
            oss << "type-" << worker->GetType() << "\n";
        }
        oss << "end-trabalhadores\n";
    }
    oss << "end_zone_info\n";
    return oss.str();
}

string Island::GetIslandSaveData() const {
    ostringstream oss;

    oss << "start_info-island\n";
    oss << "c-" << cols << "\n";
    oss << "r-" << rows << "\n";
    oss << "end_info-island\n";

    return oss.str();
}

void Island::LoadData(string filename) {
    ifstream ifs;
    ifs.open(filename);

    if (!ifs.is_open()) {
        cout << "Erro ao abrir ficheiro: " << filename << ".\n";
        return;
    }

    zone.erase(zone.begin(), zone.end());

    string data;
    int generate_map = 0;
    bool new_cell = false;
    int i_index = -1;
    while (getline(ifs, data)) {

        if (data.at(0) == 'c') {
            string _cols = data;
            _cols.erase(_cols[0], _cols[1]);
            cols = stoi(_cols);
            generate_map++;
        }

        if (data.at(0) == 'r') {
            string _rows = data;
            _rows.erase(_rows[0], _rows[1]);
            rows = stoi(_rows);
            generate_map++;
        }
        if (generate_map == 2) {
            for (int i = 0; i < cols * rows; ++i)
                zone.emplace_back(Cell::Create());
            generate_map = 0;
        }

        if (data.at(0) == 'i') {
            new_cell = true;
            string s_index = data;
            s_index.erase(s_index[0], s_index[1]);
            i_index = stoi(s_index);
        }

        if (data.at(0) == 'b') {
            data.erase(data[0], data[1]);
            string biome = data;
            zone[i_index] = Cell::Create(biome);
        }

        if (data.at(0) == 'e') {
            data.erase(data[0], data[1]);
            string building = data;
            if (!data.empty())
                zone[i_index]->SetBuilding(building);
        }

        if (data.at(0) == 'n') {
            data.erase(data[0], data[1]);
            int building_lvl = stoi(data);
            zone[i_index]->GetBuilding()->SetLevel(building_lvl);
        }

    }

    ifs.close();
}

bool Island::MoveWorker(string id, int* x, int* y) {
    for (auto &temp_zone : zone) { //Todo: Fix sigsegv here!
        if (temp_zone->GetWorker(id) != nullptr) {
            Worker *temp_worker = temp_zone->GetWorker(id);
            GetZone(*x, *y)->SetWorker(temp_worker);
            temp_zone->DeleteWorker(id);
            return true;
        }
    }
    return false;
}

Cell* Island::GetZone(const int x, const int y) {
    return zone.at(x * rows + y);
}

void Island::SetBuilding(const int x, const int y, const string& type) {
    zone.at(x * rows + y)->SetBuilding(type);
}
