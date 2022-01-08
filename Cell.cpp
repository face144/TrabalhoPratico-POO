#include "Cell.h"

Cell::Cell() {
    type = "undef";
    building = nullptr;
}

Cell::~Cell() {
    delete building;
}

Cell* Cell::Create(const string& type) {
    Cell* zone = new Cell;

    if (type == undef)
        switch (rand() % 6 + 1) {

            case 1:
                zone->type = mnt;
                break;

            case 2:
                zone->type = dsr;
                break;

            case 3:
                zone->type = pas;
                break;

            case 4:
                zone->type = flr;
                break;

            case 5:
                zone->type = pnt;
                break;

            case 6:
                zone->type = rad;
                break;

        }
    else zone->type = type;

    zone->building = Building::Create("undef");
    return zone;
}

void Cell::DestroyProbHandler(int* day) {
    if (type == pnt && building->GetDay() >= 10) {
        delete building;
        building = Building::Create("undef");
    }
    if (rand() % 100 < building->GetDestroyProb() * 100) {
        delete building;
        building = Building::Create("undef");
    }
}

void Cell::SetType(string type) {
    this->type = type;
}

string Cell::GetType() {
    return type;
}

string Cell::GetWorkerCount() {
    ostringstream oss;
    oss << worker_list.size() << ' ';
    string wrkr_cnt = oss.str();
    if (wrkr_cnt.size() > 11)
        wrkr_cnt.resize(11);
    else
        wrkr_cnt.resize(11, ' ');
    return wrkr_cnt;
}

string Cell::GetWorkersString() {
    ostringstream oss;
    if (!worker_list.empty()) {
        for (auto &worker: worker_list)
            oss << worker->GetType() << ' ';
    }
    string wrkr_cnt = oss.str();
    if (wrkr_cnt.size() > 11)
        wrkr_cnt.resize(11);
    else
        wrkr_cnt.resize(11, ' ');
    return wrkr_cnt;
}

vector <Worker*> Cell::GetWorkerList() {
    return worker_list;
}

Worker* Cell::GetWorker(string id) {
    if (!worker_list.empty())
        for (auto &worker : worker_list) {
            if (worker->GetID() == id)
                return worker;
        }
    return nullptr;
}

void Cell::SetWorker(Worker* worker) {
    worker_list.emplace_back(worker);
}

void Cell::DeleteWorker(string id) {
    for (auto &worker : worker_list) {
        if (worker->GetID() == id)
            delete worker;
    }
}

string Cell::GetBuildingType() {
    return building->GetType();
}

void Cell::SetBuilding(const string& building_type) {
    building = Building::Create(building_type);
}

Building* Cell::GetBuilding() {
    return building;
}

void Cell::KillWorkers() {
    worker_list.erase(worker_list.begin(), worker_list.end());
    //worker_list.clear();
}
