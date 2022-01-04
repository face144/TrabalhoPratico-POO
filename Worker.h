#ifndef TP_POO_RELOADED_WORKER_H
#define TP_POO_RELOADED_WORKER_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Codes.h"

using namespace std;

class Worker {
protected:
    string id;
    vector <string> buildings;

    void AssignID(int* day, int* worker_nr);

public:
    Worker();
    ~Worker();

    static Worker* Create(const string& type, int* day, int* worker_nr);
};

class Operario : public Worker {
public:
    Operario();
    ~Operario();
};

#endif //TP_POO_RELOADED_WORKER_H
