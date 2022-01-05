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
            oss << "|Trab.:" << zone.at(j * rows + i)->GetWorkerList();
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

int Island::GetCols() {
    return cols;
}

int Island::GetRows() {
    return rows;
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
