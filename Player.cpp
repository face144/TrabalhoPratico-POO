#include "Player.h"

Player::Player() {
    username = "undef";
    money = new Storage;
    iron = new Storage;
    steel = new Storage;
    coal = new Storage;
    wood = new Storage;
    wood_beam = new Storage;
    electricity = new Storage;
}

Player::~Player() {
    delete iron;
    delete steel;
    delete coal;
    delete wood;
    delete wood_beam;
    delete electricity;
}

int Player::GetMoney() {
    return money->GetCap();
}

int Player::GetIron() {
    return iron->GetCap();
}

int Player::GetSteel() {
    return steel->GetCap();
}

int Player::GetCoal() {
    return coal->GetCap();
}

int Player::GetWood() {
    return wood->GetCap();
}

int Player::GetWoodBeam() {
    return wood_beam->GetCap();
}

int Player::GetElectricity() {
    return electricity->GetCap();
}

bool Player::TakeMoney(int money) {
    if (this->money->GetCap() >= money) {
        this->money->SetCap(this->money->GetCap() - money);
        return true;
    }
    return false;
}

bool Player::TakeIron(int iron) {
    if (this->iron->GetCap() >= iron) {
        this->iron->SetCap(this->iron->GetCap() - iron);
        return true;
    }
    return false;
}

bool Player::TakeSteel(int steel) {
    if (this->steel->GetCap() >= steel) {
        this->steel->SetCap(this->steel->GetCap() - steel);
        return true;
    }
    return false;
}

bool Player::TakeCoal(int coal) {
    if (this->coal->GetCap() >= coal) {
        this->coal->SetCap(this->coal->GetCap() - coal);
        return true;
    }
    return false;
}

bool Player::TakeWood(int wood) {
    if (this->wood->GetCap() >= wood) {
        this->wood->SetCap(this->wood->GetCap() - wood);
        return true;
    }
    return false;
}

bool Player::TakeWoodBeam(int wood_beam) {
    if (this->wood_beam->GetCap() >= wood_beam) {
        this->wood_beam->SetCap(this->wood_beam->GetCap() - wood_beam);
        return true;
    }
    return false;
}

bool Player::TakeElectricity(int electricity) {
    if (this->electricity->GetCap() >= electricity) {
        this->electricity->SetCap(this->electricity->GetCap() - electricity);
        return true;
    }
    return false;
}

void Player::GiveMoney(int money) {
    this->money->SetCap(this->money->GetCap() + money);
    if (this->money->GetCap() > this->money->GetMaxCap())
        this->money->SetCap(this->money->GetMaxCap());
}

void Player::GiveIron(int iron) {
    this->iron->SetCap(this->iron->GetCap() + iron);
    if (this->iron->GetCap() > this->iron->GetMaxCap())
        this->iron->SetCap(this->iron->GetMaxCap());
}

void Player::GiveSteel(int steel) {
    if (TakeIron(1) && TakeCoal(1)) {
        this->steel->SetCap(this->steel->GetCap() + steel);
        if (this->steel->GetCap() > this->steel->GetMaxCap())
            this->steel->SetCap(this->steel->GetMaxCap());
    }
}

void Player::GiveCoal(int coal) {
    this->coal->SetCap(this->coal->GetCap() + coal);
    if (this->coal->GetCap() > this->coal->GetMaxCap())
        this->coal->SetCap(this->coal->GetMaxCap());
}

void Player::GiveWood(int wood) {
    this->wood->SetCap(this->wood->GetCap() + wood);
    if (this->wood->GetCap() > this->wood->GetMaxCap())
        this->wood->SetCap(this->wood->GetMaxCap());
}

void Player::GiveWoodBeam(int wood_beam) {
    this->wood_beam->SetCap(this->wood_beam->GetCap() + wood_beam);
    if (this->wood_beam->GetCap() > this->wood_beam->GetMaxCap())
        this->wood_beam->SetCap(this->wood_beam->GetMaxCap());
}

void Player::GiveElectricity(int electricity) {
    this->electricity->SetCap(this->electricity->GetCap() + electricity);
    if (this->electricity->GetCap() > this->electricity->GetMaxCap())
        this->electricity->SetCap(this->electricity->GetMaxCap());
}

string Player::GetUsername() {
    return username;
}

Player* Player::Create(string username) {
    auto player = new Player;

    //Assign variables
    player->username = username;

    return player;
}
