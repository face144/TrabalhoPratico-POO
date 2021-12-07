#include "App.h"

App::App() {

}

void App::Start() {
    map = Island::Create(3, 3);
}

void App::Loop() {
    while(1) {
        cout << map->PrintIsland() << endl;
        input->GetInput();
        system("pause");
    }
}


