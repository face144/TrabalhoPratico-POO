#include "App.h"

App::App() {
    player = nullptr;
    island = nullptr;
    type = "undef";
    day = new int;
    worker_cnt = new int;
    x = -1;
    y = -1;
}

App::~App() {
    delete player;
    delete island;
    delete day;
    type.erase();
    for (auto &i : input)
        i.erase();
}

void App::Init() {
    system("cls");
    cout << "Nome do jogador: ";
    string username;
    cin >> username;

    system("cls");
    cout << "Mapa\n\n";
    cout << "Numero de filas: ";
    int rows; cin >> rows;
    cout << "Numero de colunas: ";
    int cols; cin >> cols;
    system("cls");
    cout << "Escreva 'ajuda' para a lista de comandos. Bom jogo!\n";

    srand(time(nullptr));
    player = Player::Create(username);
    island = Island::Create(cols, rows);
    //input.erase(input.begin(),input.end());
    //day = new int;
    *day = 1;
    *worker_cnt = 1;

}

void App::PrintIsland() {
    cout << island->PrintIsland();
}

void App::PrintHUD() {
    ostringstream oss;

    oss << "Dia " << *day << " | Jogador: " << player->GetUsername() << endl << endl;

    oss << "Dinheiro: " << player->GetMoney() << "$" << endl;
    oss << "Madeira      - " << player->GetWood()        << " | Vigas de Madeira - " << player->GetWoodBeam() << endl;
    oss << "Ferro        - " << player->GetIron()        << " | Vigas de Aco     - " << player->GetSteel()    << endl;
    oss << "Eletricidade - " << player->GetElectricity() << " | Carvao           - " << player->GetCoal()     << endl;

    cout << oss.str();
}

void App::GetInput() {
    int cmd_code;
    string user_input;
    cout << player->GetUsername() << ':';
    cin >> ws;
    getline(cin, user_input);


    istringstream iss( user_input );
    for ( string keyword ; iss >> keyword ; )
        this->input.emplace_back(keyword);

    cmd_code = CheckSyntax();

    Execute(cmd_code);
    input.clear();
}

int App::CheckSyntax() {

    if (input.empty())
        return 0;

    input.resize(20, " ");

    for (int i = 0; i < input.size(); ++i) {

        if (input.at(i) == "exec") {
            type = input.at(++i);
            return 1;

        } else if (input.at(i) == "cons") {
            i++;
            if (input.at(i) == "minaf" ||
                input.at(i) == "minac" ||
                input.at(i) == "central" ||
                input.at(i) == "bat" ||
                input.at(i) == "fund" ||
                input.at(i) == "filt") {
                type = input.at(i);
                x = stoi(input.at(++i)) - 1;
                y = stoi(input.at(++i)) - 1;
                return 2;
            }

        } else if (input.at(i) == "liga") {
            x = stoi(input.at(++i)) - 1;
            y = stoi(input.at(++i)) - 1;
            return 3;

        } else if (input.at(i) == "move") {
            return 4;

        } else if (input.at(i) == "cont") {
            type = input.at(++i);
            return 5;

        } else if (input.at(i) == "list") {
            return 6;

        } else if (input.at(i) == "next") {
            return 7;

        } else if (input.at(i) == "save") {
            return 8;

        } else if (input.at(i) == "des") {
            x = stoi(input.at(++i)) - 1;
            y = stoi(input.at(++i)) - 1;
            return 9;

        } else if (input.at(i) == "vende") {
            return 10;

        } else if (input.at(i) == "novojogo") {
            type = input.at(++i);
            x = stoi(input.at(++i)) - 1;
            y = stoi(input.at(++i)) - 1;
            return 11;

        }else if (input.at(i) == "load") {
            return 12;

        } else if (input.at(i) == "lvlup"){
            x = stoi(input.at(++i)) - 1;
            y = stoi(input.at(++i)) - 1;
            return 13;

        } else { return 0; } }

}

bool App::CheckCoords() {
    if (x > 0 && x <= island->GetCols() &&
        y > 0 && y <= island->GetRows()   )
        return true;

    return false;
}

void App::Execute(int cmd_code) {
    string username;
    switch (cmd_code) {
        case 1:
            ReadFromFile();
            break;

        case 2:
            if ( CheckPurchase() )
                island->GetZone(x, y)->SetBuilding(type);
            else
                cout << "Erro na construcao do edificio!\n";
            break;

        case 3:
            if (island->GetZone(x, y)->GetBuildingType() == "undef")
                cout << "Nenhum edifico nessa zona!\n";
            else
                island->GetZone(x, y)->GetBuilding()->SetOnline();
            break;

        case 4:
            cout << "Comando nao implementado!\n";
            break;

        case 5:
            //Todo: Criar funcao para ver os guitos e por o que esta aqui nessa funcao;
            /*Worker::Create(type, day, worker_cnt);
            int *_x, *_y;
            *_x = 1;
            *_y = 1;
            island->MoveWorker("1.1", _x, _y);

            worker_cnt++;
            type = "undef";*/
            cout << "Comando nao implementado!\n";
            break;

        case 6:
            system("cls");
            PrintHUD();
            PrintIsland();
            break;

        case 7:
            NewDay();
            break;

        case 8:
            SaveGame();
            break;

        case 9:
            if (island->GetZone(x, y)->GetBuildingType() == "undef")
                cout << "Nenhum edifico nessa zona!\n";
            else
                island->GetZone(x, y)->GetBuilding()->SetOffline();
            break;

        case 10:
            cout << "Comando nao implementado!\n";
            break;

        case 11:
            island = Island::Create(x, y);
            player = Player::Create(type);
            break;

        case 12:
            cout << "Nome de utilizador: ";
            cin >> username;
            LoadGame(username);
            break;

        case 13:
            LevelUp();
            break;

        default:
            cout << "Comando invalido!\n";
            break;
    }
    type = "undef";
    x = -1;
    y = -1;
}

void App::ReadFromFile() {
    fstream fs;
    string command;

    fs.open(type, ios::in);
    if (!fs.is_open()) {
        cout << "Erro ao abrir o ficheiro: " << type << ".\n";
        return;
    }

    while (!fs.eof()) {
        getline(fs, command);
        istringstream iss(command);
        for ( string keyword ; iss >> keyword ; )
            this->input.emplace_back(keyword);
        int cmd_code = CheckSyntax();
        Execute(cmd_code);
        input.clear();
    }
}

bool App::CheckPurchase() {
    if (type == "minaf" || type == "minac") {
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeWoodBeam(mina_cost * 2);
        else
            return player->TakeWoodBeam(mina_cost);

    }

    if (type == "central") {
        if (x - 1 >= 0) {
            if (island->GetZone(x - 1, y)->GetType() == flr) {
                if (island->GetZone(x, y)->GetType() == mnt)
                    return player->TakeMoney(central_cost * 2);
                else
                    return player->TakeMoney(central_cost);
            }
        }
        if (x + 1 <= island->GetCols()) {
            if (island->GetZone(x + 1, y)->GetType() == flr) {
                if (island->GetZone(x, y)->GetType() == mnt)
                    return player->TakeMoney(central_cost * 2);
                else
                    return player->TakeMoney(central_cost);
            }
        }
        if (y - 1 >= 0) {
            if (island->GetZone(x, y - 1)->GetType() == flr) {
                if (island->GetZone(x, y)->GetType() == mnt)
                    return player->TakeMoney(central_cost * 2);
                else
                    return player->TakeMoney(central_cost);
            }
        }
        if (y + 1 <= island->GetRows()) {
            if (island->GetZone(x, y + 1)->GetType() == flr) {
                if (island->GetZone(x, y)->GetType() == mnt)
                    return player->TakeMoney(central_cost) * 2;
                else
                    return player->TakeMoney(central_cost);
            }
        }
    }

    if (type == "bat") {
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeSteel(bat_cost_steel * 2) && player->TakeMoney(bat_cost_money * 2);
        else
            return player->TakeSteel(bat_cost_steel) && player->TakeMoney(bat_cost_money);
    }

    if (type == "fund") {
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeMoney(fund_cost * 2);
        else
            return player->TakeMoney(fund_cost);
    }

    if (type == "filt") {
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeMoney(filt_cost * 2);
        else
            return player->TakeMoney(filt_cost);
    }
    return false;
}

bool App::LevelUp() {  //Trocar valores
    if(island->GetZone(x, y)->GetBuildingType() == minaf) {
        if (island->GetZone(x, y)->GetBuilding()->LevelUp() && player->TakeWoodBeam(1) && player->TakeMoney(15))
            cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
        else
            cout << "Recursos insuficientes!\n";

    } else if(island->GetZone(x, y)->GetBuildingType() == minac) {
        if (island->GetZone(x, y)->GetBuilding()->LevelUp() && player->TakeWoodBeam(1) && player->TakeMoney(10))
            cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
        else
            cout << "Recursos insuficientes!\n";

    } else if(island->GetZone(x, y)->GetBuildingType() == bat) {
        if (island->GetZone(x, y)->GetBuilding()->LevelUp() && player->TakeMoney(5))
            cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
        else
            cout << "Recursos insuficientes!\n";

    } else if (island->GetZone(x, y)->GetBuildingType() == rad) {
        if (island->GetZone(x, y)->GetBuilding()->LevelUp() && player->TakeMoney(10))
            cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
        else
            cout << "Recursos insuficientes!\n";

    } else if (island->GetZone(x, y)->GetBuildingType() == "undef") {
        cout << "Nenhum edificio nessa zona!\n";

    } else {
        cout << "Esse edificio nao pode ser melhorado.\n";
    }
}

void App::GiveResources(int x, int y) {
        string building_type = island->GetZone(x, y)->GetBuildingType();
    if (!island->GetZone(x, y)->GetBuilding()->IsOnline())
        return;

    if (island->GetZone(x, y)->GetType() == dsr) {
        if (island->GetZone(x, y)->GetBuildingType() == minaf) {
            //if (island->GetZone(x,y)->GetWorker(type) != nullptr)
            player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);

        } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
            //if (island->GetZone(x,y)->GetWorker(type) != nullptr)
            player->GiveCoal(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);

        } else if (island->GetZone(x, y)->GetBuildingType() == fund) {
            bool give_output_minaf = false;
            bool give_output_minacC = false;
            if (x - 1 >= 0) {
                if (island->GetZone(x - 1, y)->GetBuildingType() == minaf)
                    give_output_minaf = true;
                else if (island->GetZone(x - 1, y)->GetBuildingType() == minac ||
                         island->GetZone(x - 1, y)->GetBuildingType() == central)
                    give_output_minacC = true;
            }
            if (x + 1 <= island->GetCols()) {
                if (island->GetZone(x + 1, y)->GetBuildingType() == minaf)
                    give_output_minaf = true;
                else if (island->GetZone(x + 1, y)->GetBuildingType() == minac ||
                         island->GetZone(x + 1, y)->GetBuildingType() == central)
                    give_output_minacC = true;
            }
            if (y - 1 >= 0) {
                if (island->GetZone(x, y - 1)->GetBuildingType() == minaf)
                    give_output_minaf = true;
                else if (island->GetZone(x, y - 1)->GetBuildingType() == minac ||
                         island->GetZone(x, y - 1)->GetBuildingType() == central)
                    give_output_minacC = true;
            }
            if (y + 1 <= island->GetRows()) {
                if (island->GetZone(x, y + 1)->GetBuildingType() == minaf)
                    give_output_minaf = true;
                else if (island->GetZone(x, y + 1)->GetBuildingType() == minac ||
                         island->GetZone(x, y + 1)->GetBuildingType() == central)
                    give_output_minacC = true;
            }
            if (give_output_minaf && give_output_minacC)
                player->GiveSteel(island->GetZone(x, y)->GetBuilding()->GetOutput() * 2);
        }


    } else if (island->GetZone(x, y)->GetType() == mnt) {
            if (island->GetZone(x, y)->GetBuildingType() == minaf) {
                player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() * 2);

            } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
                player->GiveCoal(island->GetZone(x, y)->GetBuilding()->GetOutput() * 2);

            } else if (island->GetZone(x, y)->GetBuildingType() == central) {
                bool give_output = false;

                if (x - 1 >= 0) {
                    if (island->GetZone(x - 1, y)->GetBuildingType() == bat)
                        give_output = true;
                }
                if (x + 1 <= island->GetCols()) {
                    if (island->GetZone(x + 1, y)->GetBuildingType() == bat)
                        give_output = true;
                }
                if (y - 1 >= 0) {
                    if (island->GetZone(x, y - 1)->GetBuildingType() == bat)
                        give_output = true;
                }
                if (y + 1 <= island->GetRows()) {
                    if (island->GetZone(x, y + 1)->GetBuildingType() == bat)
                        give_output = true;
                }
                if (give_output)
                    player->GiveElectricity(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);

            } else if (island->GetZone(x, y)->GetBuildingType() == fund) {
                bool give_output_minaf = false;
                bool give_output_minacC = false;
                if (x - 1 >= 0) {
                    if (island->GetZone(x - 1, y)->GetBuildingType() == minaf)
                        give_output_minaf = true;
                    else if (island->GetZone(x - 1, y)->GetBuildingType() == minac ||
                             island->GetZone(x - 1, y)->GetBuildingType() == central)
                        give_output_minacC = true;
                }
                if (x + 1 <= island->GetCols()) {
                    if (island->GetZone(x + 1, y)->GetBuildingType() == minaf)
                        give_output_minaf = true;
                    else if (island->GetZone(x + 1, y)->GetBuildingType() == minac ||
                             island->GetZone(x + 1, y)->GetBuildingType() == central)
                        give_output_minacC = true;
                }
                if (y - 1 >= 0) {
                    if (island->GetZone(x, y - 1)->GetBuildingType() == minaf)
                        give_output_minaf = true;
                    else if (island->GetZone(x, y - 1)->GetBuildingType() == minac ||
                             island->GetZone(x, y - 1)->GetBuildingType() == central)
                        give_output_minacC = true;
                }
                if (y + 1 <= island->GetRows()) {
                    if (island->GetZone(x, y + 1)->GetBuildingType() == minaf)
                        give_output_minaf = true;
                    else if (island->GetZone(x, y + 1)->GetBuildingType() == minac ||
                             island->GetZone(x, y + 1)->GetBuildingType() == central)
                        give_output_minacC = true;
                }
                if (give_output_minaf && give_output_minacC)
                    player->GiveSteel(island->GetZone(x, y)->GetBuilding()->GetOutput() * 2);

            } else {

                if (island->GetZone(x, y)->GetBuildingType() == minaf) {
                    player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput());

                } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
                    player->GiveCoal(island->GetZone(x, y)->GetBuilding()->GetOutput());

                } else if (island->GetZone(x, y)->GetBuildingType() == central) {
                    bool give_output = false;

                    if (x - 1 >= 0) {
                        if (island->GetZone(x - 1, y)->GetBuildingType() == bat)
                            give_output = true;
                    }
                    if (x + 1 <= island->GetCols()) {
                        if (island->GetZone(x + 1, y)->GetBuildingType() == bat)
                            give_output = true;
                    }
                    if (y - 1 >= 0) {
                        if (island->GetZone(x, y - 1)->GetBuildingType() == bat)
                            give_output = true;
                    }
                    if (y + 1 <= island->GetRows()) {
                        if (island->GetZone(x, y + 1)->GetBuildingType() == bat)
                            give_output = true;
                    }
                    if (give_output)
                        player->GiveElectricity(island->GetZone(x, y)->GetBuilding()->GetOutput());

                } else if (island->GetZone(x, y)->GetBuildingType() == fund) {
                    bool give_output_minaf = false;
                    bool give_output_minacC = false;
                    if (x - 1 >= 0) {
                        if (island->GetZone(x - 1, y)->GetBuildingType() == minaf)
                            give_output_minaf = true;
                        else if (island->GetZone(x - 1, y)->GetBuildingType() == minac ||
                                 island->GetZone(x - 1, y)->GetBuildingType() == central)
                            give_output_minacC = true;
                    }
                    if (x + 1 <= island->GetCols()) {
                        if (island->GetZone(x + 1, y)->GetBuildingType() == minaf)
                            give_output_minaf = true;
                        else if (island->GetZone(x + 1, y)->GetBuildingType() == minac ||
                                 island->GetZone(x + 1, y)->GetBuildingType() == central)
                            give_output_minacC = true;
                    }
                    if (y - 1 >= 0) {
                        if (island->GetZone(x, y - 1)->GetBuildingType() == minaf)
                            give_output_minaf = true;
                        else if (island->GetZone(x, y - 1)->GetBuildingType() == minac ||
                                 island->GetZone(x, y - 1)->GetBuildingType() == central)
                            give_output_minacC = true;
                    }
                    if (y + 1 <= island->GetRows()) {
                        if (island->GetZone(x, y + 1)->GetBuildingType() == minaf)
                            give_output_minaf = true;
                        else if (island->GetZone(x, y + 1)->GetBuildingType() == minac ||
                                 island->GetZone(x, y + 1)->GetBuildingType() == central)
                            give_output_minacC = true;
                    }
                    if (give_output_minaf && give_output_minacC)
                        player->GiveSteel(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);
                }
            }
     }
}


void App::NewDay() {
    (*day)++;
    for (int i = 0; i < island->GetRows(); i++)
        for (int j = 0; j < island->GetCols(); j++) {
            GiveResources(i, j);
            island->GetZone(i, j)->DestroyProbHandler(day);
            //island->GetZone(i, j)->GetBuilding()->NextDay();
            if (island->GetZone(i, j)->GetType() == rad)
                island->GetZone(i, j)->KillWorkers();
        }


    if (*day % 10 == 0)
        island->RadiationUpdate(*day);

    cout << "It's a new daaaaaawwnnn, It's a new daaaaaay!\n";
}

void App::SaveGame() const {
    fstream fs;
    ostringstream filename;

    filename << player->GetUsername() << ".txt";
    fs.open(filename.str(), ios::out);

    if (!fs.is_open()) {
        cout << "Erro ao criar ficheiro: " << filename.str() << ".\n";
        return;
    }

    fs << island->GetIslandSaveData().data() << island->GetZonesSaveData();
    fs.close();

    cout << "Ficheiro guardado como '" << filename.str() << "'.\n";
}

void App::LoadGame(string &username) {
    ostringstream filename;
    filename << username << ".txt";
    island->LoadData(filename.str());
}
