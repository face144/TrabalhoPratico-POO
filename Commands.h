#ifndef TRABALHOPRATICO_POO_RELOADED_COMMANDS_H
#define TRABALHOPRATICO_POO_RELOADED_COMMANDS_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Commands {
private:
    string* input;
    bool Validator();

public:
    Commands();
    ~Commands();
    void GetInput();

};


#endif //TRABALHOPRATICO_POO_RELOADED_COMMANDS_H
