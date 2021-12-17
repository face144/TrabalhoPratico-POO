#ifndef TRABALHOPRATICO_POO_RELOADED_CELL_H
#define TRABALHOPRATICO_POO_RELOADED_CELL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

#include "Building.h"

using namespace std;

class Cell {
private:
    string type;
    Building* building = new Building;
    //Worker

public:
    int id;

    Cell();
    ~Cell();

    static Cell* Create();
    string GetType();

    string GetBuildingType();

    void SetBuilding(string type);
};


#endif //TRABALHOPRATICO_POO_RELOADED_CELL_H
