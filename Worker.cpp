#include "Worker.h"

Worker::Worker() {
    id = "undef";
    quitProb = 0;
    days = 0;
}

Worker::~Worker() {
    id.erase(id.begin(), id.end());
    buildings.erase(buildings.begin(), buildings.end());
}

void Worker::AssignID(int* day, int* worker_nr) {
    ostringstream oss;
    oss << worker_nr;
    oss << '.';
    oss << day;
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
        worker = new Operario();
        worker->AssignID(day, worker_nr);
    } else if (type == "lenhador") {
        worker = new Lenhador();
        worker->AssignID(day, worker_nr);
    } else if (type == "mineiro") {
        worker = new Mineiro;
        worker->AssignID(day, worker_nr);
    } else {
        return nullptr;
    }

    return worker;
}

void Worker::UpdateQuitProb(int &day){
    if(type == oper) {
        if (days >= 10)
            quitProb = 0.05;
    } else if (type == mine) {
        if (days >= 2)
            quitProb = 0.1;
    }
}

float Worker::GetQuitProb() const {
    return quitProb;
}

Operario::Operario() {
    type = oper;
    buildings.emplace_back(fund);
    buildings.emplace_back(central);
}

Lenhador::Lenhador() {
    type = lenh;
}

Mineiro::Mineiro() {
    type = mine;
    buildings.emplace_back(minac);
    buildings.emplace_back(minaf);
}
