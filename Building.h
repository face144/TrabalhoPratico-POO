#ifndef TRABALHOPRATICO_POO_RELOADED_BUILDING_H
#define TRABALHOPRATICO_POO_RELOADED_BUILDING_H

#include <iostream>
#include "Storage.h"

using namespace std;

class Building {
protected:
    string type;
    int level, max_level, output;
    float destroy_prob;
    Storage* storage;



public:
    Building();
    ~Building();

    static Building* Create(const string& type);
    int GetOutput() const;
    string GetType() const;

    bool LevelUp();


};

class Minaf : public Building{
public:
    Minaf();
};

class Minac : public Building{
public:
    Minac();
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
