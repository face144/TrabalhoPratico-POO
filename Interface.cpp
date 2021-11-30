#include "Interface.h"

Interface::Interface(string username) : username(username) {

}


void Interface::mapInit() {
    do {
        cout << endl <<"Ola " << username << "! Antes de comecarmos preciso de informacao sobre o mapa onde vais jogar.";
        cout << endl << "Quantas linhas queres que o mapa tenha? ";
        cin >> map_rows;
        cout << endl << "Por ultimo, quantas colunas queres no teu mapa? ";
        cin >> map_cols;
    } while (map_rows < min_rows || map_rows > max_rows && map_cols < min_cols || map_cols > max_cols);
}


void Interface::gameScene() {
    do {
        //Jogo
        getCommand();
    } while (!victory);
}


void Interface::getCommand() {
    string temp_command;
    do {
        cout << endl << username << ": ";
        getline(cin, temp_command);
    } while (temp_command.empty());

    char *command[temp_command.length()];
    *command[0] = temp_command;

    char *command_keys;
    command_keys = strtok(*command, " ");


    for (int i = 0; i < 5; ++i) {
        cout << command_keys[i] << ' ';
    }

    if (!searchCommand(&command_keys))
        cout << "Erro: Comando nao reconhecido." << endl;

    else
        cout << "Sucesso: Comando executado." << endl;
}


bool Interface::searchCommand(char **command_keys) {
    int i = 0;
    if (command_keys[i++] == cmd_build) {
        if (command_keys[i++] == code_iron_mine) {
            int col = stoi(command_keys[i++]) - 48, row = stoi(command_keys[i++]) - 48;
            if (col < map_cols || col > 0 && row < map_rows || col > 0) {
                //Dar o setBuilding na ilha;
                return true;
            }
        }
    }
    return false;
}


#pragma region Gets

string Interface::getUsername() {
    return username;
}


int Interface::getMapRows() const {
    return map_rows;
}

int Interface::getMapCols() const {
    return map_cols;
}

#pragma endregion