#ifndef TRABALHOPRATICO_POO_RELOADED_CELL_H
#define TRABALHOPRATICO_POO_RELOADED_CELL_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>

#include "Worker.h"
#include "Building.h"

using namespace std;

class Cell {
private:
    string type;
    Building* building;
    vector <Worker*> worker_list;

public:
    //int id;

    Cell();
    ~Cell();

    static Cell* Create();
    void DestroyProbHandler(int* day);
    string GetWorkerCount();
    string GetType();
    string GetWorkerList();
    Worker* GetWorker(string id);
    void SetWorker(Worker* worker);
    void DeleteWorker(string id);
    string GetBuildingType();

    void SetBuilding(const string& type);
    Building* GetBuilding();
};


#endif //TRABALHOPRATICO_POO_RELOADED_CELL_H
