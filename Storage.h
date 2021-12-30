#ifndef TRABALHOPRATICO_POO_RELOADED_STORAGE_H
#define TRABALHOPRATICO_POO_RELOADED_STORAGE_H
#include <iostream>

using namespace std;

class Storage {
private:
    int cap;
    int max_cap;

public:
    Storage();
    ~Storage();

    int GetCap();
    int GetMaxCap();

    void SetCap(int cap);
    void SetMaxCap(int max_cap);


};


#endif //TRABALHOPRATICO_POO_RELOADED_STORAGE_H
