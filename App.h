#ifndef TRABALHOPRATICO_POO_RELOADED_APP_H
#define TRABALHOPRATICO_POO_RELOADED_APP_H

#include <iostream>
#include <string>
#include "Island.h"
#include "Player.h"

using namespace std;

class App {
private:
    Island* island;
    Player* player;

    int x, y, *day;
    string type;

    vector <string> input;

    int CheckSyntax();
    bool CheckCoords();
    void Execute(int cmd_code);
    bool CheckPurchase(string type);
    void GiveResources(int x, int y);
    void NewDay();

public:
    App();
    ~App();

    void PrintIsland();
    void PrintHUD();
    void Init();
    void GetInput();
};


#endif //TRABALHOPRATICO_POO_RELOADED_APP_H
