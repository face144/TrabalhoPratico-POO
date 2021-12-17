#include "Storage.h"

Storage::Storage() {

}

Storage::~Storage() {

}

void Storage::SetQuantity(int quantity) {
    this->quantity += quantity;
}

Storage* Storage::Create(string type) {
    auto* storage = new Storage;
    storage->quantity = 0;

    if (type == "iron")
        storage->sell_money = 1;

    return storage;
}

int Storage::GetQuantity() {
    return quantity;
}
