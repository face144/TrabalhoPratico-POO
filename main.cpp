#include <iostream>
#include <istream>
#include "App.h"

using namespace std;

int main() {
    srand(time(nullptr));

    for (int i = 0; i < 3; ++i) {
        cout << rand() % 6 + 1 << " ";
    }

    system("pause");

    App game;
    game.Start();
    game.Loop();
    return 0;
}
