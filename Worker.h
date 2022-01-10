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
    string type;
    int days;
    float quitProb;

    void AssignID(int* day, int* worker_nr);

public:
    Worker();
    ~Worker();

    string GetType();
    string GetID();
    static Worker* Create(const string& type, int* days, int* worker_nr);
    void UpdateQuitProb(int &days);
    float GetQuitProb();

};

class Operario : public Worker {
public:
    Operario();
    ~Operario();
};

class Lenhador : public Worker {
public:
    Lenhador();
    ~Lenhador();
};

class Mineiro : public Worker{
public:
    Mineiro();
    ~Mineiro();
};
#endif //TP_POO_RELOADED_WORKER_H
