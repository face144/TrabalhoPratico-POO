#include "Resource.h"

Resource::Resource() {
    quantity = 0;
}

void Resource::SetQuantity(int quantity) {
    this->quantity += quantity;
}

