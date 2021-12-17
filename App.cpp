#include "App.h"

App::App() {
    player = new Player;
}

App::~App() {
    delete player;
}

void App::Start() {
    player->SetUsername("face");
    map = Island::Create(3, 3);
}

void App::Loop() {
    while(1) {
        int cmd_code = 1;
        day++;
        while (cmd_code != 2) {

            if ( cmd_code == 1) {
                cout << PrintHUD() << endl;
                cout << map->PrintIsland() << endl << endl;
            }

            cout << player->GetUsername() << ':';
            cmd_code = CommandHandler();

            if ( cmd_code == 0 )
                cout << "Erro: Comando invalido." << endl;
            else
                system("cls");
        }
    }
}

string App::PrintHUD() {
    ostringstream oss;

    oss << "Dia " << day << " | Jogador: " << player->GetUsername() << endl << endl;

    oss << "0.00$" << endl;
    oss << "Madeira      - 0" << " | Vigas de Madeira       - 0" << endl;
    oss << "Ferro        - " << player->GetIronQuantity() << " | Vigas de Aco           - 0" << endl;
    oss << "Eletricidade - 0" << " | Eletricidade em pacote - 0" << endl;

    return oss.str();
}

int App::CommandHandler() {
    /**@bug Os comandos sao adicionados ao vetor
     * em vez de simplesmente substituir o primeiro
     * indice pelo novo comando o que faz com que a
     * funcao apenas verifique o primeiro comando escrito
     */

    vector <string> command = player->SetInput(); /// @def Separa as palavras do comando num vetor
    int  i = 0, exit_code = -1;

    /// @def Validacao do comando
    if (command.at(i) == "next")
        exit_code = 2;

    else if ( command.at(i) == "cons" )
        exit_code = 1;

    else exit_code = 0;

    for (int j = 0; j < command.size(); ++j) {
        command.at(i).clear();
    }
    return exit_code;

    //Todo: Execucao do comando
}

bool App::PurchaseHandler(string type) {
    //Todo: Validacao (ONLY!!!) de compra

    if (true)
        return true;
    else
        return false;
}


