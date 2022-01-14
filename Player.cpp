#include "Player.h"

Player::Player() {
    username = "undef";
    money = 100;
    storage = nullptr;
}

Player::~Player() {
    delete storage;
}

int Player::GetMoney() {
    return money;
}

int Player::GetIron() {
    return storage->GetCap("iron");
}

int Player::GetSteel() {
    return storage->GetCap("steel");
}

int Player::GetCoal() {
    return storage->GetCap("coal");
}

int Player::GetWood() {
    return storage->GetCap("wood");
}

int Player::GetWoodBeam() {
    return storage->GetCap("wood_beam");
}

int Player::GetElectricity() {
    return storage->GetCap("electricity");
}

bool Player::TakeMoney(int money) {
    if (this->money >= money) {
        this->money = this->money - money;
        return true;
    }else return false;

}

bool Player::TakeIron(int iron) {
    if (this->storage->GetCap("iron") >= iron) {
        this->storage->SetCap("iron", this->storage->GetCap("iron") - iron);
        return true;
    }else return false;

}

bool Player::TakeSteel(int steel) {
    if (storage->GetCap("steel") >= steel) {
        this->storage->SetCap("steel" ,this->storage->GetCap("steel") - steel);
        return true;
    }else return false;

}

bool Player::TakeCoal(int coal) {
    if (storage->GetCap("coal") >= coal) {
        this->storage->SetCap("coal",this->storage->GetCap("coal") - coal);
        return true;
    }else return false;

}

bool Player::TakeWood(int wood) {
    if (storage->GetCap("wood") >= wood) {
        this->storage->SetCap("wood",this->storage->GetCap("wood") - wood);
        return true;
    }else return false;

}

bool Player::TakeWoodBeam(int wood_beam) {
    if (storage->GetCap("wood_beam") >= wood_beam) {
        this->storage->SetCap("wood_beam",this->storage->GetCap("wood_beam") - wood_beam);
        return true;
    }else return false;

}

bool Player::TakeElectricity(int electricity) {
    if (storage->GetCap("electricity") >= electricity) {
        this->storage->SetCap("electricity",this->storage->GetCap("electricity") - electricity);
        return true;
    }else return false;

}

void Player::GiveMoney(int money) {
    this->money += money;
}

void Player::GiveIron(int iron) {
    storage->SetCap("iron", storage->GetCap("iron") + iron);
    if (storage->GetCap("iron") > storage->GetMaxCap("iron"))
        storage->SetCap("iron", storage->GetMaxCap("iron"));
}

void Player::GiveSteel(int steel) {
    if (TakeIron(1) && TakeCoal(1)) {
        storage->SetCap("steel", storage->GetCap("steel") + steel);
        if (storage->GetCap("steel") > storage->GetMaxCap("steel"))
            storage->SetCap("steel", storage->GetMaxCap("steel"));
    }
}

void Player::GiveCoal(int coal) {
    storage->SetCap("coal", storage->GetCap("coal") + coal);
    if (storage->GetCap("coal") > storage->GetMaxCap("coal"))
        storage->SetCap("coal", storage->GetMaxCap("coal"));
}

void Player::GiveWood(int wood) {
    storage->SetCap("wood", storage->GetCap("wood") + wood);
    if (storage->GetCap("wood") > storage->GetMaxCap("wood"))
        storage->SetCap("wood", storage->GetMaxCap("wood"));
}

void Player::GiveWoodBeam(int wood_beam) {
    storage->SetCap("wood_beam", storage->GetCap("wood_beam") + wood_beam);
    if (storage->GetCap("wood_beam") > storage->GetMaxCap("wood_beam"))
        storage->SetCap("wood_beam", storage->GetMaxCap("wood_beam"));
}

void Player::GiveElectricity(int electricity) {
    storage->SetCap("electricity", storage->GetCap("electricity") + electricity);
    if (storage->GetCap("electricity") > storage->GetMaxCap("electricity"))
        storage->SetCap("electricity", storage->GetMaxCap("electricity"));
}

string Player::GetUsername() {
    return username;
}

Player* Player::Create(string username) {
    auto player = new Player;

    //Assign variables
    player->storage = Storage::Create();
    player->username = username;

    return player;
}
