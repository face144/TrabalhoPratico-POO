#ifndef TRABALHOPRATICO_POO_RELOADED_CELL_H
#define TRABALHOPRATICO_POO_RELOADED_CELL_H

#include <iostream>
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
    Worker* worker;

public:
    int id;

    Cell();
    ~Cell();

    static Cell* Create();
    void DestroyProbHandler();
    int GetOutput();
    string GetType();
    Worker* GetWorker();
    string GetBuildingType();

    void SetBuilding(const string& type);
    Building* GetBuilding();
};


#endif //TRABALHOPRATICO_POO_RELOADED_CELL_H
