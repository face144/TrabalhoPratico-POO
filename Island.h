#ifndef TRABALHOPRATICO_POO_RELOADED_ISLAND_H
#define TRABALHOPRATICO_POO_RELOADED_ISLAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include "Cell.h"
#include "Codes.h"

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
    void LoadData(const string& filename);
    void RadiationUpdate(int& day);

    bool MoveWorker(string id, int* x, int* y);
    void SpawnWorker(Worker* worker);

    Cell* GetZone(int x, int y);
    void SetBuilding(int x, int y, const string& type);
};


#endif //TRABALHOPRATICO_POO_RELOADED_ISLAND_H
