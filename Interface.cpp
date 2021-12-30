#include "Interface.h"

Interface::Interface() {
    game = new App;
}

Interface::~Interface() {
}

void Interface::Start() {
    game->Init();
}

void Interface::Loop() {
    while (true) {
        game->GetInput();
    }
}
