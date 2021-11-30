#ifndef TRABALHOPRATICO_POO_RELOADED_INTERFACE_H
#define TRABALHOPRATICO_POO_RELOADED_INTERFACE_H

#include <iostream>
#include <cstring>

using namespace std;

class Interface {

#pragma region Constants

    const int max_char_default = 100;

    const int min_rows = 3;
    const int min_cols = 3;

    const int max_rows = 16;
    const int max_cols = 8;

    const string cmd_build = "cons";
    const string code_iron_mine = "minaf";

#pragma endregion

    string username;
    int map_rows;
    int map_cols;
    bool victory = false;

    //Island map;

    bool searchCommand(char **command_keys);
    void getCommand();

public:

    Interface(string username);

    void mapInit();
    void gameScene();
    //void saveGame();


#pragma region Gets

    string getUsername();

    int getMapRows() const;
    int getMapCols() const;

#pragma endregion

};


#endif //TRABALHOPRATICO_POO_RELOADED_INTERFACE_H
