#ifndef TRABALHOPRATICO_POO_RELOADED_PLAYER_H
#define TRABALHOPRATICO_POO_RELOADED_PLAYER_H

#include <iostream>
#include <vector>
#include "Storage.h"

using namespace std;

class Player {
    string username;
    Storage* storage;
    int money;

public:
    Player();
    ~Player();

    int* GetMoney();
    int* GetIron();
    int* GetSteel();
    int* GetCoal();
    int* GetWood();
    int* GetWoodBeam();
    int* GetElectricity();

    bool TakeMoney(int money);
    bool TakeIron(int iron);
    bool TakeSteel(int steel);
    bool TakeCoal(int coal);
    bool TakeWood(int wood);
    bool TakeWoodBeam(int wood_beam);
    bool TakeElectricity(int electricity);

    void GiveMoney(int money);
    void GiveIron(int iron);
    void GiveSteel(int steel);
    void GiveCoal(int coal);
    void GiveWood(int wood);
    void GiveWoodBeam(int wood_beam);
    void GiveElectricity(int electricity);

    string GetUsername();

    static Player* Create(string username);
};


#endif //TRABALHOPRATICO_POO_RELOADED_PLAYER_H
