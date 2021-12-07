#include "Cell.h"

Cell *Cell::Create() {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 5); // define the range

    Cell* zone;
    zone->type = distr(gen);

    cout << "Celula Criada!" << endl;

    return zone;
}
