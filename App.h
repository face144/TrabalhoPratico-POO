#ifndef TRABALHOPRATICO_POO_RELOADED_APP_H
#define TRABALHOPRATICO_POO_RELOADED_APP_H

#include <iostream>
#include "Island.h"
#include "Commands.h"

using namespace std;

class App {
    Island* map;
    Commands* input;

public:
    App();

    void Start();
    void Loop();

};


#endif //TRABALHOPRATICO_POO_RELOADED_APP_H
