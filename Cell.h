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

    static Cell* Create(const string& type = undef);
    void DestroyProbHandler(int* day);
    void QuitProbHandler(int &day);
    string GetWorkerCount();
    void SetType(string type);
    string GetType();
    string GetWorkersString();
    vector <Worker*> GetWorkerList();
    Worker* GetWorker(string id);
    void SetWorker(string type, int &day, int &worker_nr);
    void DeleteWorker(string id);
    string GetBuildingType();

    void SetBuilding(const string& type = "undef");
    Building* GetBuilding();
    void KillWorkers();
};


#endif //TRABALHOPRATICO_POO_RELOADED_CELL_H
