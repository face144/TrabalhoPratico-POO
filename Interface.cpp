#include "Interface.h"

Interface::Interface() {
    game = new App;
}

Interface::~Interface() {
    delete game;
}

void Interface::SplashScreen() { //Todo: Apagar dps...
    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n";
    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n";
    cout << "OOOOOOOOO                          OOOOOO                          OOOOOO                          OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO                          OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOO   OOOOOOOOOOOOOOOOOOOO   OOOOOOOOO\n";
    cout << "OOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO                          OOOOOO                          OOOOOOOOO\n";
    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n";
    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO TP - 2021/22\n";
    cout << "                                        Trabalho realizado por:                                             \n";
    cout << "                                        Jose Parente - a2020142069                                          \n";
    cout << "                                        Goncalo Leite - (nr de aluno)                                       \n\n";

    cout << "                                        A carregar simulacao...                                             \n";
    cout << "                                        Por favor aguarde.                                                  \n";
    system("cls");
}

void Interface::Start() {
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Todo: Also apagar dps...
    //SplashScreen();
    game->Init();

}

void Interface::Loop() {
    while (true) {
        game->GetInput();
    }
}
