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

    const string minaf = "minaf        ";
    const string minac = "minac        ";
    const string central = "central      ";
    const string bat = "bat          ";
    const string fund = "fund         ";

    const string mnt = "mnt        ";
    const string flr = "flr        ";
    const string pnt = "pnt        ";
    const string dsr = "dsr        ";
    const string pas = "pas        ";

    int minaf_cost;
    int minac_cost;
    int central_cost;
    int bat_cost_money;
    int bat_cost_steel;
    int fund_cost;


    int CheckSyntax();
    bool CheckCoords();
    void Execute(int cmd_code);
    bool CheckPurchase(string type);
    bool CheckLevelUp(int x, int y);
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
