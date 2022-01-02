#include "App.h"

App::App() {
    player = nullptr;
    island = nullptr;
    type = "undef";
    day = nullptr;
    x = -1;
    y = -1;
    minaf_cost = 10;
    minac_cost = 10;
    central_cost = 15;
    bat_cost_money = 10;
    bat_cost_steel = 10;
    fund_cost = 10;
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
    srand(time(0));
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

    } else if (input.at(i) == "next") {
        return 11;

    } else if (input.at(i) == "save") {
        return 12;

    } else if (input.at(i) == "nivel"){
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
            if ( CheckPurchase(type) )
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
            break;

        case 11:
            cout << "Comando nao implementado!\n";
            break;

        case 12:
            cout << "Comando nao implementado!\n";
            break;

        case 13:



        default:
            cout << "Comando invalido!\n";
            break;
    }
}

bool App::CheckPurchase(string type) {
    if (type == "minaf" || type == "minac")
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeWoodBeam(10 * 2);
        else
            return player->TakeWoodBeam(10);

    if (type == "central")
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeMoney(15 * 2);
        else
            return player->TakeMoney(15);

    if (type == "bat")
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeWoodBeam(10 * 2) && player->TakeMoney(10 * 2);
        else
            return player->TakeWoodBeam(10) && player->TakeMoney(10);

    if (type == "fund")
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeMoney(10 * 2);
        else
            return player->TakeMoney(10);

    if (type == "filt")
        if (island->GetZone(x, y)->GetType() == mnt)
            return player->TakeMoney(20 * 2);
        else
            return player->TakeMoney(20);

    return false;
}

bool App::CheckLevelUp(int x, int y) {  //Trocar valores 
    if(island->GetZone(x, y)->GetBuildingType() == minaf) {
        if (player->TakeWoodBeam(10))
            return player->TakeWoodBeam(10);
        else if (player->TakeMoney(100))
            return player->TakeMoney(100);

    } else if(island->GetZone(x, y)->GetBuildingType() == minac){
        if(player->TakeWoodBeam(10))
            return player->TakeWoodBeam(10);
        else if (player->TakeMoney(100))
            return player->TakeMoney(100);
    
    } else if(island->GetZone(x, y)->GetBuildingType() == central){
         if (player->TakeMoney(15))
            return player->TakeMoney(15);

    } else if(island->GetZone(x, y)->GetBuildingType() == bat) {
        
        if (player->TakeMoney(10) && player->TakeWoodBeam(10))
            return (player->TakeMoney(10) && player->TakeWoodBeam(10));
        
        else if(player->TakeMoney(10) && player->TakeSteel(10))
            return (player->TakeMoney(10) && player->TakeSteel(10));
    
    } else if (island->GetZone(x, y)->GetBuildingType() == fund){
        
        if(player->TakeMoney(10))
            return (player->TakeMoney(10));
    } 
 
    
        



}

void App::GiveResources(int x, int y) {
    string building_type = island->GetZone(x, y)->GetBuildingType();
    if (island->GetZone(x, y)->GetType() == dsr) {
        if (island->GetZone(x, y)->GetBuildingType() == minaf) {
            player->GiveIron(island->GetZone(x, y)->GetBuilding()->GetOutput() / 2);

        } else if (island->GetZone(x, y)->GetBuildingType() == minac) {
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
