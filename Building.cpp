#include "Building.h"

Building::Building() {
    type = "             ";
    level = 0;
    max_level = 0;
    destroy_prob = 0;
}

Building::~Building() {

}

Building* Building::Create(string type) {
    auto* building = new Building;

    if (type == "minaf") {
        building->type = "minaf        ";
        building->level = 0;
        building->max_level = 5;
        building->output = 1;
        building->destroy_prob = 0.15;
    }

    return building;
}

int Building::GetOutput() const {
    return output;
}

string Building::GetType() const {
    return type;
}

bool Building::LevelUp() {
    if (level < max_level) {
        level++;
        return true;
    }

    return false;
}
