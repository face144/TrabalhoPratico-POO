#include "Cell.h"

Cell::Cell() {
    type = "undef";
}

Cell::~Cell() {
    delete building;
}

Cell* Cell::Create() {
    srand(time(nullptr));
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

string Cell::GetType() {
    return type;
}

string Cell::GetBuildingType() {
    return building->GetType();
}

void Cell::SetBuilding(string type) {
    delete building;
    this->building = Building::Create(type);
}
