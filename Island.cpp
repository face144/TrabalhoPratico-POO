#include "Island.h"

Island::Island(){

}

Island::~Island() {
    zone.clear();
}

Island* Island::Create(int cols, int rows) {
    auto* map = new Island;
    map->cols = cols;
    map->rows = rows;
    map->zone.reserve(cols * rows);
    for (int i = 0; i < cols * rows; ++i) {
        map->zone.emplace_back(Cell::Create());
    }
    return map;
}

string Island::PrintIsland() {
    ostringstream oss;
    oss << "Imprimir Ilha" << endl;
    return oss.str();
}
