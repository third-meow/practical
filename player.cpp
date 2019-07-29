#include<exception>
#include"player.h"

	

Player::Player() {
	name = "unnamed";
	pos = 0;
	cash = 9500;
}

void Player::pay(int amount) {
	// Remove amount
	cash -= amount;
	// If player has negitive money, throw bankrupt exception
	if (cash < 0) {
		throw BankruptException();
	}
}

bool Player::voluntary_pay(int amount) {
	// If player has enough, remove funds and return true
	if (cash >= amount) {
		cash -= amount;
		return true;
	} 
	// If player doesnt have enough, return false
	else {
		return false;
	}
}

void Player::receive(int amount) {
	cash += amount;
}


