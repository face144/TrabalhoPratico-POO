#include "Resources.h"

Resource::Resource() {
    type = nullptr;
    value = nullptr;
    quantity = nullptr;
    max = nullptr;
}

int* Resource::GetMax() {
    return max;
}

int* Resource::GetQuant() {
    return quantity;
}

string Resource::GetType() {
    return type;
}

float* Resource::GetValue() {
    return value;
}

void Resource::SetMax(int& max) {
    *this->max = max;
}

void Resource::SetQuant(int& quant) {
    *this->quantity = quant;
}


Resource* Resource::Create(string type) {

    Resource* resource;

    if (type == "iron") {
        resource = new Iron;
        *resource->value = 1;

    } else if (type == "steel") {
        resource = new Steel;
        *resource->value = 2;

    } else if (type == "coal") {
        resource = new Coal;
        *resource->value = 1;

    } else if (type == "wood") {
        resource = new Wood;
        *resource->value = 1;

    } else if (type == "wood_beam") {
        resource = new WoodBeam;
        *resource->value = 2;

    } else if (type == "electricity") {
        resource = new Eletricity;
        *resource->value = 1.5;

    } else
        return nullptr;

    *resource->quantity = 1000000;
    *resource->max = 1000;
    resource->type = type;
    return resource;

}
