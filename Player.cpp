#include "Player.h"

Player::Player() {

}

Player::~Player() {
    delete iron;

/*    delete money;
    delete steel;
    delete coal;
    delete wood;
    delete wood_beam;
    delete electricity;*/
}

vector <string> Player::SetInput() {
    return this->input.GetInput();
}

void Player::SetUsername(string username) {
    this->username = username;
}

void Player::SetIron(int iron) {
    this->iron->SetQuantity(iron);
}

/*void Player::SetMoney(int money) {
    this->money->SetQuantity(money);
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
}*/

string Player::GetUsername() {
    return username;
}

int Player::GetIronQuantity() {
    return iron->GetQuantity();
}
