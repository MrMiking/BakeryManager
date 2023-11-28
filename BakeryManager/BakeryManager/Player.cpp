#include "Player.h"

void Player::AddMoney(float money) {
	this->money += money;
}

void Player::RemoveMoney(float money) {
	this->money -= money;
}

float Player::ShowMoney() {
	return this->money;
}

void Player::InitializeRandom() {
	srand(time(0));
}

int Player::GenerateRandomNumberBetween(int min, int max) {
	return (rand() % (max - min + 1) + min);
}