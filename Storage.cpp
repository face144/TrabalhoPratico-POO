#include "Storage.h"

Storage::Storage() {

}

Storage::~Storage() {
    storage.erase(storage.begin(), storage.end());
}

Storage* Storage::Create() {
    Storage* storage = new Storage;

    storage->storage.push_back(Resource::Create("iron"));
    storage->storage.push_back(Resource::Create("steel"));
    storage->storage.push_back(Resource::Create("coal"));
    storage->storage.push_back(Resource::Create("wood"));
    storage->storage.push_back(Resource::Create("wood_beam"));
    storage->storage.push_back(Resource::Create("electricity"));

    return storage;
}

int* Storage::GetCap(string type) {
    for (auto &r : storage) {
        if (r->GetType() == type)
            return r->GetQuant();
    }
    return nullptr;
}

int* Storage::GetMaxCap(string type) {
    for (auto &r : storage) {
        if (r->GetType() == type)
            return r->GetMax();
    }
    return nullptr;
}

void Storage::SetCap(string type, int cap) {
    // Todo: ver se da erro por usar ponteiro
    for (auto &r : storage) {
        if (r->GetType() == type)
            return r->SetQuant(cap);
    }
}

void Storage::SetMaxCap(string type, int max_cap) {
    // Todo: ver se da erro por usar ponteiro
    for (auto &r : storage) {
        if (r->GetType() == type)
            return r->SetMax(max_cap);
    }
}
