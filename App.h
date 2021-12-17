#ifndef TRABALHOPRATICO_POO_RELOADED_APP_H
#define TRABALHOPRATICO_POO_RELOADED_APP_H

#include <iostream>
#include "Island.h"
#include "Player.h"

using namespace std;

class App {
    int day = 0;

    Island* map;
    Player* player;

    string PrintHUD();
    int CommandHandler();
    bool PurchaseHandler(string type);

public:
    App();
    ~App();

    void Start();
    void Loop();
};


#endif //TRABALHOPRATICO_POO_RELOADED_APP_H
