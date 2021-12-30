#ifndef TRABALHOPRATICO_POO_RELOADED_CELL_H
#define TRABALHOPRATICO_POO_RELOADED_CELL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>

#include "Building.h"

using namespace std;

class Cell {
private:
    string type;
    Building* building;
    //Worker

public:
    int id;

    Cell();
    ~Cell();

    static Cell* Create();
    int GetOutput();
    string GetType();

    string GetBuildingType();

    void SetBuilding(const string& type);
    Building* GetBuilding();
};


#endif //TRABALHOPRATICO_POO_RELOADED_CELL_H
