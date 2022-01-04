#include "App.h"

App::App() {
    player = nullptr;
    island = nullptr;
    type = "undef";
    day = nullptr;
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
    srand(time(nullptr));
    player = Player::Create("face");
    island = Island::Create(5, 5);
    //input.erase(input.begin(),input.end());
    day = new int;
    *day = 1;
}

void App::PrintIsland() {
    cout << island->PrintIsland();
}

void App::PrintHUD() {
    ostringstream oss;

    oss << "Dia " << *day << " | Jogador: " << player->GetUsername() << endl << endl;

    oss << "Guitos: " << player->GetMoney() << "$" << endl;
    oss << "Madeira      - " << player->GetWood()        << " | Vigas de Madeira       - " << player->GetWoodBeam() << endl;
    oss << "Ferro        - " << player->GetIron()        << " | Vigas de Aco           - " << player->GetSteel()    << endl;
    oss << "Eletricidade - " << player->GetElectricity() << " | Carvaummmmm            - " << player->GetCoal()     << endl;

    cout << oss.str();
}

void App::GetInput() {
    int cmd_code;
    string user_input;
    cout << player->GetUsername() << ':';
    getline(cin, user_input);

    istringstream iss( user_input );
    for ( string keyword ; iss >> keyword ; )
        this->input.emplace_back(keyword);

    cmd_code = CheckSyntax();
    Execute(cmd_code);
    input.clear();
}

int App::CheckSyntax() {
    int i = 0;

    if (input.at(i) == "exec") {
        return 1;

    } else if (input.at(i) == "cons") {
        if (input.at(++i) == "minaf" ||
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

    } else if (input.at(i) == "save") {
        return 12;

    } else if (input.at(i) == "lvlup"){
        x = stoi(input.at(++i)) - 1;
        y = stoi(input.at(++i)) - 1;
        return 13;

    } else { return 0; }

}

bool App::CheckCoords() {
    //Todo: Redo deeez nuts
}

void App::Execute(int cmd_code) {
    switch (cmd_code) {
        case 1:
            cout << "Comando nao implementado!\n";
            break;

        case 2:
            if ( CheckPurchase() )
                island->GetZone(x, y)->SetBuilding(type);
            else
                cout << "Recursos Insuficientes\n";
            type = "undef";
            x = -1;
            y = -1;
            break;

        case 3:
            if (island->GetZone(x, y)->GetBuildingType() == "undef")
                cout << "Nenhum edifico nessa zona!\n";
            else
                island->GetZone(x, y)->GetBuilding()->SetOnline();
            x = -1;
            y = -1;
            break;

        case 4:
            cout << "Comando nao implementado!\n";
            break;

        case 5:
            //Todo: Criar funcao para ver os guitos e por o que esta aqui nessa funcao;
            Worker::Create(type, day, worker_cnt);

            worker_cnt++;
            type = "undef";
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
            cout << "Comando nao implementado!\n";
            break;

        case 9:
            if (island->GetZone(x, y)->GetBuildingType() == "undef")
                cout << "Nenhum edifico nessa zona!\n";
            else
                island->GetZone(x, y)->GetBuilding()->SetOffline();
            x = -1;
            y = -1;
            break;

        case 10:
            cout << "Comando nao implementado!\n";

        case 12:
            cout << "Comando nao implementado!\n";
            break;

        case 13:
            LevelUp();
            x = -1;
            y = -1;
            break;

        default:
            cout << "Comando invalido!\n";
            break;
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
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeMoney(central_cost * 2);
        else
            return player->TakeMoney(central_cost);
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
        if (player->TakeWoodBeam(1) && player->TakeMoney(15)) {
            if (island->GetZone(x, y)->GetBuilding()->LevelUp())
                cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
            else
                cout << "Recursos insuficientes!\n";
        }

    } else if(island->GetZone(x, y)->GetBuildingType() == minac) {
        if (player->TakeWoodBeam(1) && player->TakeMoney(10)) {
            if (island->GetZone(x, y)->GetBuilding()->LevelUp())
                cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
            else
                cout << "Recursos insuficientes!\n";
        }

    } else if(island->GetZone(x, y)->GetBuildingType() == bat) {
        if (player->TakeMoney(5)) {
            if (island->GetZone(x, y)->GetBuilding()->LevelUp())
                cout << "Edifico melhorado para o nivel " << island->GetZone(x, y)->GetBuilding()->GetLevel() << ".\n";
            else
                cout << "Recursos insuficientes!\n";
        }

    } else if (island->GetZone(x, y)->GetBuildingType() == "undef") {
        cout << "Nenhum edificio nessa zona!\n";

    } else {
        cout << "Esse edificio nao pode ser melhorado.\n";
    }
}

void App::GiveResources(int x, int y) {
    string building_type = island->GetZone(x, y)->GetBuildingType();
    if (island->GetZone(x, y)->GetType() == dsr) {
        if (island->GetZone(x, y)->GetBuildingType() == minaf) {
            if (island->GetZone(x,y)->GetWorker() != nullptr)
                player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);

        } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
            if (island->GetZone(x,y)->GetWorker() != nullptr)
                player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);
        }
    } else if (island->GetZone(x, y)->GetType() == mnt) {
        if (island->GetZone(x, y)->GetBuildingType() == minaf) {
            player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() * 2);

        } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
            player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() * 2);
        }
    } else {
        if (island->GetZone(x, y)->GetBuildingType() == minaf) {
            player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput());

        } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
            player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput());
        }
    }
}


void App::NewDay() {
    (*day)++;
    for (int i = 0; i < island->GetRows(); i++)
        for (int j = 0; j < island->GetCols(); j++) {
            GiveResources(i, j);
            island->GetZone(i, j)->DestroyProbHandler();
        }

    cout << "It's a new daaaaaawwnnn, It's a new daaaaaay!\n";
}
