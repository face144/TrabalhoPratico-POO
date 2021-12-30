#include <iostream>
#include <istream>
#include "Interface.h"

using namespace std;

int main() {
    auto* game = new Interface;
    game->Start();
    game->Loop();
    delete game;
    return 0;
}
