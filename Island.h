#ifndef TRABALHOPRATICO_POO_RELOADED_ISLAND_H
#define TRABALHOPRATICO_POO_RELOADED_ISLAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Cell.h"

using namespace std;

class Island {
    int cols, rows;
    vector <Cell*> zone;

public:
    Island();
    ~Island();

    static Island* Create(int cols, int rows);
    string PrintIsland();
};


#endif //TRABALHOPRATICO_POO_RELOADED_ISLAND_H
