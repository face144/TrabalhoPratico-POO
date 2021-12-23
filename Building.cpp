#include "Building.h"


Building::Building() {
    type = nullptr;
    level = NULL;
    max_level = NULL;
    destroy_prob = NULL;
    storage = nullptr;
}

Building::~Building() {

}

int Building::GetOutput() const {
    return output;
}

string Building::GetType() const {
    return type;
}

Building* Building::Create(const string& type) {
    Building* building;

    if (type == "minaf")
        building = new Minaf;

    else if (type == "minac")
        building = new Minac;

    else if (type == "central")
        building = new Central;

    else if (type == "bat")
        building = new Bat;

    else if (type == "fund")
        building = new Fund;

    else if (type == "edx")
        building = new Edx;

    else
        return nullptr;


    return building;

}

Minaf::Minaf() {
    type = "minaf";
    level = 1;
    max_level = 5;
    destroy_prob = 0.15;

}

Minac::Minac() {
    type = "minac";
    level = 1;
    max_level = 5;
    destroy_prob = 0.1;
}

Central::Central() {
    type = "central";
    level = 1;
    max_level = 1;
    destroy_prob = 0;
}

Bat::Bat() {
    type = "bat";
    level = 1;
    max_level = 5;
    destroy_prob = 0;
}

Fund::Fund() {
    type = "fund";
    level = 1;
    max_level = 1;
    destroy_prob = 0;
}

Edx::Edx() {
    type = "edx";
    level = 1;
    max_level = 1;
    destroy_prob = 0;
}
