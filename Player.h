#ifndef TRABALHOPRATICO_POO_RELOADED_PLAYER_H
#define TRABALHOPRATICO_POO_RELOADED_PLAYER_H

#include <iostream>
#include <vector>
#include "Storage.h"
#include "Commands.h"

using namespace std;

class Player {
private:
    Commands input;
    string username;
    Storage* iron = Storage::Create("iron");

/*    Storage* money = new Storage;
    Storage* steel = new Storage;
    Storage* coal = new Storage;
    Storage* wood = new Storage;
    Storage* wood_beam = new Storage;
    Storage* electricity = new Storage;*/

public:
    Player();
    ~Player();

    vector <string> SetInput();
    void SetUsername(string username);
    void SetIron(int iron);

/*    void SetMoney(int money);
    void SetSteel(int steel);
    void SetCoal(int coal);
    void SetWood(int wood);
    void SetWoodBeam(int wood_beam);
    void SetElectricity(int electricity);*/

    string GetUsername();
    int GetIronQuantity();
};


#endif //TRABALHOPRATICO_POO_RELOADED_PLAYER_H
