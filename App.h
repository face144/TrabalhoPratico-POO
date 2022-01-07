#ifndef TRABALHOPRATICO_POO_RELOADED_APP_H
#define TRABALHOPRATICO_POO_RELOADED_APP_H

#include <fstream>
#include <string>
#include "Island.h"
#include "Player.h"
#include "Codes.h"

using namespace std;

class App {
private:
    Island* island;
    Player* player;

    int x, y, *day, *worker_cnt;
    string type;

    vector <string> input;


    int CheckSyntax();
    bool CheckCoords();
    void Execute(int cmd_code);
    bool CheckPurchase();
    bool LevelUp();
    void GiveResources(int x, int y);
    void NewDay();
    void ReadFromFile();
    void SaveGame() const;
    void LoadGame();

public:
    App();
    ~App();

    void PrintIsland();
    void PrintHUD();
    void Init();
    void GetInput();
};


#endif //TRABALHOPRATICO_POO_RELOADED_APP_H
