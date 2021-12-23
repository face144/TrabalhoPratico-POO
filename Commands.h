#ifndef TRABALHOPRATICO_POO_RELOADED_COMMANDS_H
#define TRABALHOPRATICO_POO_RELOADED_COMMANDS_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class Commands {
    vector <string> input;

public:
    Commands();
    ~Commands();

    static int GetInput();
};


#endif //TRABALHOPRATICO_POO_RELOADED_COMMANDS_H
