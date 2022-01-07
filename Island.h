#ifndef TRABALHOPRATICO_POO_RELOADED_ISLAND_H
#define TRABALHOPRATICO_POO_RELOADED_ISLAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
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

    int GetCols() const;
    int GetRows() const;
    string GetZonesSaveData() const;
    string GetIslandSaveData() const;
    void LoadData(string filename);

    bool MoveWorker(string id, int* x, int* y);

    Cell* GetZone(int x, int y);
    void SetBuilding(int x, int y, const string& type);
};


#endif //TRABALHOPRATICO_POO_RELOADED_ISLAND_H
