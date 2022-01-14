#ifndef TRABALHOPRATICO_POO_RELOADED_STORAGE_H
#define TRABALHOPRATICO_POO_RELOADED_STORAGE_H

#include <iostream>
#include <vector>
#include "Resource.h"

using namespace std;

class Storage {
private:
    vector <Resource*> storage;

public:
    Storage();
    ~Storage();

    static Storage* Create();

    int GetCap(string type);
    int GetMaxCap(string type);

    void SetCap(string type, int cap);
    void SetMaxCap(string type, int max_cap);


};


#endif //TRABALHOPRATICO_POO_RELOADED_STORAGE_H
