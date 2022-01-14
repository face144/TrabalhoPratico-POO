#include "Storage.h"

Storage::Storage() {
    storage.push_back(Resource::Create("iron"));
    storage.push_back(Resource::Create("steel"));
    storage.push_back(Resource::Create("coal"));
    storage.push_back(Resource::Create("wood"));
    storage.push_back(Resource::Create("wood_beam"));
    storage.push_back(Resource::Create("electricity"));
}

Storage::~Storage() {
    storage.erase(storage.begin(), storage.end());
}

Storage* Storage::Create() {
    return new Storage;
}

int Storage::GetCap(string type) {
    for (auto &r : storage) {
        if (r->GetType() == type)
            return r->GetQuant();
    }
}

int Storage::GetMaxCap(string type) {
    for (auto &r : storage) {
        if (r->GetType() == type)
            return r->GetMax();
    }
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
