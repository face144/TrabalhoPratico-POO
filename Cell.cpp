#include "Cell.h"

Cell::Cell() {
    type = "undef";
    building = Building::Create("undef");
}

Cell::~Cell() {
    delete building;
}

Cell* Cell::Create() {
    Cell* zone = new Cell;

    switch (rand() % 6 + 1) {

        case 1:
            zone->type = "mnt        ";
            break;

        case 2:
            zone->type = "dsr        ";
            break;

        case 3:
            zone->type = "pas        ";
            break;

        case 4:
            zone->type = "flr        ";
            break;

        case 5:
            zone->type = "pnt        ";
            break;

        case 6:
            zone->type = "rad        ";
            break;

    }
    return zone;
}

int Cell::GetOutput() {
    if (type == "mnt        ") {
        if (building->GetType() == "minaf        " || building->GetType() == "minac        ")
            return building->GetOutput() * 2;

    } else if (type == "dsr        ") {
        if (building->GetType() == "minaf        " || building->GetType() == "minac        ")
            return building->GetOutput() / 2;

    } else if (type == "pas        ") {
        if (building->Get == "minaf        " || building->GetType() == "minac        ")
            return building->GetOutput() / 2;
}

string Cell::GetType() {
    return type;
}

string Cell::GetBuildingType() {
    return building->GetType();
}

void Cell::SetBuilding(const string& building_type) {
    building = nullptr;
    building = Building::Create(building_type);
}

Building* Cell::GetBuilding() {
    return building;
}
