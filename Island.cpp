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

    oss << "---start_zone_info" << endl;
    for (int z = 0; z < zone.size(); ++z) {
        oss << "i" << z << "" << endl;
        oss << "b" << zone[z]->GetType() << "" << endl;
        oss << "e" << zone[z]->GetBuildingType() << "" << endl;
        oss << "n" << zone[z]->GetBuilding()->GetLevel() << "" << endl;
        oss << "t" << zone[z]->GetWorkerCount() << "" << endl;

        oss << "---start-trabalhadores" << endl;
        for (auto & worker : zone[z]->GetWorkerList()) {
            oss << "id" << worker->GetID() << "" << endl;
            oss << "ty" << worker->GetType() << "" << endl;
        }
        oss << "---end-trabalhadores" << endl;
    }
    oss << "---end_zone_info" << endl;
    return oss.str();
}

string Island::GetIslandSaveData() const {
    ostringstream oss;

    oss << "---start_info-island" << endl;
    oss << "c" << cols << "" << endl;
    oss << "r" << rows << "" << endl;
    oss << "---end_info-island" << endl;

    return oss.str();
}

void Island::LoadData(const string& filename) {
    fstream fs;
    fs.open(filename, ios::in);

    if (!fs.is_open()) {
        cout << "Erro ao abrir ficheiro: " << filename << "." << endl;
        return;
    }

    string data;
    int generate_map = 0;
    bool new_cell = false;
    int i_index = -1;
    while (getline(fs, data)) {

        if (data.at(0) == 'c') {
            string _cols = data;
            _cols.erase(_cols.begin());
            cols = stoi(_cols);
            generate_map++;
        }

        if (data.at(0) == 'r') {
            string _rows = data;
            _rows.erase(_rows.begin());
            rows = stoi(_rows);
            generate_map++;
        }
        /*if (generate_map == 2) {
            for (int i = 0; i < cols * rows; ++i)
                zone.emplace_back(Cell::Create());
            generate_map = 0;
        }*/

        if (data.at(0) == 'i') {
            new_cell = true;
            string s_index = data;
            s_index.erase(s_index.begin());
            i_index = stoi(s_index);
        }

        if (data.at(0) == 'b') {
            data.erase(data.begin());
            string biome = data;
            zone.at(i_index) = Cell::Create(biome);
        }

        if (data.at(0) == 'e') {
            data.erase(data.begin());
            string building = data;
            zone.at(i_index)->SetBuilding(building);
        }

        if (data.at(0) == 'n') {
            data.erase(data.begin());
            int building_lvl = stoi(data);
            zone.at(i_index)->GetBuilding()->SetLevel(building_lvl);
        }

    }

    fs.close();

    cout << "Jogo carregado com sucesso!" << endl;
}

void Island::RadiationUpdate(int& day) {

    for (int i = 0; i < zone.size(); i++) {

        int left = i - 1;
        int right = i + 1;
        int above = i - cols;
        int below = i + cols;

        int lottery = rand() % 4 + 1;

        if (zone.at(i)->GetType() == rad && zone.at(i)->GetBuildingType() != filt) {

            zone.at(i)->SetBuilding(undef);

            if (left >= 0 && lottery == 1) {
                zone.at(left)->SetType(rad);
                zone.at(left)->SetBuilding(undef);

            } else if (right <= zone.size() - 1 && lottery == 2) {
                zone.at(right)->SetType(rad);
                zone.at(right)->SetBuilding(undef);

            } else if (above >= 0 && lottery == 3) {
                zone.at(above)->SetType(rad);
                zone.at(above)->SetBuilding(undef);

            } else if (below <= zone.size() - 1 && lottery == 4) {
                zone.at(below)->SetType(rad);
                zone.at(below)->SetBuilding(undef);
            }
        } else if (zone.at(i)->GetType() == rad &&
                   zone.at(i)->GetBuildingType() == filt &&
                   zone.at(i)->GetBuilding()->GetLevel() == 2) {

            switch (rand() % 6 + 1) {

                case 1:
                    zone.at(i)->SetType(mnt);
                    break;

                case 2:
                    zone.at(i)->SetType(flr);
                    break;

                case 3:
                    zone.at(i)->SetType(pnt);
                    break;

                case 4:
                    zone.at(i)->SetType(dsr);
                    break;

                case 5:
                    zone.at(i)->SetType(pas);
                    break;
            }
        }
    }
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
