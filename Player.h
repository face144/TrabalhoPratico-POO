#ifndef TRABALHOPRATICO_POO_RELOADED_PLAYER_H
#define TRABALHOPRATICO_POO_RELOADED_PLAYER_H

#include <iostream>
#include <vector>
#include "Resource.h"

using namespace std;

class Player {
private:
    string username;
    Resource* money;
    Resource* iron;
    Resource* steel;
    Resource* coal;
    Resource* wood;
    Resource* wood_beam;
    Resource* electricity;

public:
    Player();
    ~Player();

    void SetMoney(int money);
    void SetIron(int iron);
    void SetSteel(int steel);
    void SetCoal(int coal);
    void SetWood(int wood);
    void SetWoodBeam(int wood_beam);
    void SetElectricity(int electricity);

};


#endif //TRABALHOPRATICO_POO_RELOADED_PLAYER_H
