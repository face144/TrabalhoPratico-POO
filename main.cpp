#include <iostream>
#include "Interface.h"

using namespace std;

int main() {
    cout << "Nome de utilizador: ";
    string username;
    cin >> username;

    Interface interface(username);
    interface.mapInit();
    interface.gameScene();

    return 0;
}
