#include "Player.h"

void Player::SetMoney(int money) {
    this->money->SetQuantity(money);
}

void Player::SetIron(int iron) {
    this->iron->SetQuantity(iron);
}

void Player::SetSteel(int steel) {
    this->steel->SetQuantity(steel);
}

void Player::SetCoal(int coal) {
    this->coal->SetQuantity(coal);
}

void Player::SetWood(int wood) {
    this->wood->SetQuantity(wood);
}

void Player::SetWoodBeam(int wood_beam) {
    this->wood_beam->SetQuantity(wood_beam);
}

void Player::SetElectricity(int electricity) {
    this->electricity->SetQuantity(electricity);
}

