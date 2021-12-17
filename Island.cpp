#include "Island.h"

Island::Island(){

}

Island::~Island() {
    for (auto &i : zone) {
        delete i;
    }
}

Island* Island::Create(int cols, int rows) {
    auto* map = new Island;
    map->cols = cols;
    map->rows = rows;
    for ( int i = 0; i < cols * rows + 1; ++i )
        map->zone.emplace_back(Cell::Create());

    return map;
}

string Island::PrintIsland() {
    ostringstream oss;

    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i)
            oss << " -----------------";
        oss << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Bioma:" << zone.at(rows * cols)->GetType();
        oss << '|' << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Ed.:" << zone.at(rows * cols)->GetBuildingType();
        oss << '|' << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Trab.:           ";
        oss << '|' << endl;

        for (int i = 0; i < cols; ++i)
            oss << "|Total:           ";
        oss << '|' << endl;
    }

    for (int i = 0; i < cols; ++i)
        oss << " -----------------";

    return oss.str();
}
