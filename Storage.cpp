#include "Storage.h"

Storage::Storage() {
    cap = 100;
    max_cap = 1000;
}

Storage::~Storage() {

}

int Storage::GetCap() {
    return cap;
}

int Storage::GetMaxCap() {
    return max_cap;
}

void Storage::SetCap(int cap) {
    this->cap = cap;
}

void Storage::SetMaxCap(int max_cap) {
    this->max_cap = max_cap;
}
