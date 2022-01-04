#include "Worker.h"

Worker::Worker() {
    id = "undef";
}

Worker::~Worker() {
    id.erase(id.begin(), id.end());
    buildings.erase(buildings.begin(), buildings.end());
}

void Worker::AssignID(int* day, int* worker_nr) {
    ostringstream oss;
    oss << worker_nr;
    oss << day;
    oss << '.';
    id = oss.str();
}

string Worker::GetType() {
    return type;
}

string Worker::GetID() {
    return id;
}

Worker* Worker::Create(const string& type, int* day, int* worker_nr) {
    Worker* worker;
    if (type == "operario") {
        worker = new Operario;
        worker->AssignID(day, worker_nr);
    } else {
        return nullptr;
    }

    return worker;
}

Operario::Operario() {
    type = "O";
    buildings.emplace_back(fund);
    buildings.emplace_back(central);
}
