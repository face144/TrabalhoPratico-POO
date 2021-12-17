#ifndef TRABALHOPRATICO_POO_RELOADED_BUILDING_H
#define TRABALHOPRATICO_POO_RELOADED_BUILDING_H

#include <iostream>

using namespace std;

class Building {
private:
    string type;
    int level, max_level, output;
    float destroy_prob;



public:
    Building();
    ~Building();

    static Building* Create(string type);
    int GetOutput() const;
    string GetType() const;

    bool LevelUp();


};


#endif //TRABALHOPRATICO_POO_RELOADED_BUILDING_H
