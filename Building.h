#ifndef TRABALHOPRATICO_POO_RELOADED_BUILDING_H
#define TRABALHOPRATICO_POO_RELOADED_BUILDING_H

#include <iostream>
#include "Storage.h"

using namespace std;

class Building {
protected:
    string type;
    int level, max_level;
    float destroy_prob;
    bool is_online;
    int cap;
    int max_cap;
    int output;

public:
    Building();
    ~Building();

    bool IsOnline() const;
    void SetOffline();
    void SetOnline();
    float GetDestroyProb() const;
    int GetOutput() const;

    static Building* Create(const string& type);
    string GetType() const;


};

class Minaf : public Building{
public:
    Minaf();
    void levelUp();
};

class Minac : public Building{
public:
    Minac();
    void levelUp();
};

class Central : public Building{
public:
    Central();
};

class Bat : public Building{
public:
    Bat();
};

class Fund : public Building{
public:
    Fund();
};

class Edx : public Building{
public:
    Edx();
};



#endif //TRABALHOPRATICO_POO_RELOADED_BUILDING_H
