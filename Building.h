#ifndef TRABALHOPRATICO_POO_RELOADED_BUILDING_H
#define TRABALHOPRATICO_POO_RELOADED_BUILDING_H

#include <iostream>
#include "Codes.h"
#include "Storage.h"
#include "Player.h"

using namespace std;

class Building {
protected:
    string type;
    int level, max_level;
    float destroy_prob;
    bool is_online;
    bool needs_worker;
    int cap;
    int max_cap;
    int output;
    int days;

public:
    Building();
    ~Building();

    void NextDay();
    int GetDay();
    bool LevelUp();
    bool IsOnline() const;
    bool NeedsWorker() const;
    void SetOffline();
    void SetOnline();
    void SetLevel(int lvl);
    int GetLevel();
    float GetDestroyProb() const;
    int GetOutput() const;

    static Building* Create(const string& type);
    string GetType() const;


};

class Minaf : public Building{
public:
    void GetOutput(Player* player) const;
    Minaf();
};

class Minac : public Building{
public:
    void GetOutput(Player* player) const;
    Minac();
};

class Central : public Building{
public:
    void GetOutput(Player* player) const;
    Central();
};

class Bat : public Building{
public:
    void GetOutput(Player* player) const;
    Bat();
};

class Fund : public Building{
public:
    void GetOutput(Player* player) const;
    Fund();
};

class Edx : public Building{
public:
    Edx();
};



#endif //TRABALHOPRATICO_POO_RELOADED_BUILDING_H
