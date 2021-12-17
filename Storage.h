#ifndef TRABALHOPRATICO_POO_RELOADED_STORAGE_H
#define TRABALHOPRATICO_POO_RELOADED_STORAGE_H

#include <iostream>

using namespace std;

class Storage {
private:
    int quantity;
    int sell_money;

public:
    Storage();
    ~Storage();

    void SetQuantity(int quantity);
    static Storage* Create(string type);

    int GetQuantity();
};


#endif //TRABALHOPRATICO_POO_RELOADED_STORAGE_H
