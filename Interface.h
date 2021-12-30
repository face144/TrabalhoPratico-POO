#ifndef TRABALHOPRATICO_POO_RELOADED_INTERFACE_H
#define TRABALHOPRATICO_POO_RELOADED_INTERFACE_H

#include "App.h"

class Interface {
    App* game;
public:
    Interface();
    ~Interface();

    void Start();
    void Loop();

};


#endif //TRABALHOPRATICO_POO_RELOADED_INTERFACE_H
