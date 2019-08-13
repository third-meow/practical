#include<exception>
#include"player.h"

using namespace std;

Player::Player() {
	name = "unnamed";
	pos = 0;
	cash = 9500; }

void Player::pay(int amount) {
	// Remove amount
	cash -= amount;
	// If player has negitive money, throw bankrupt exception
	if (cash < 0) {
		throw BankruptException();
	}
}

// Pay if player has enough funds
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

bool Player::ask_pay(int amount, string property_name) {
	string res;
	cout << "Buy " << property_name << " for " << amount << " ? [y/n]" << endl;
	cin >> res;
	res = tolower(res.front());

	if (res == "y") {
		if (cash >= amount) {
			pay(amount);
			return true;
		} else {
			cout << "Not enough funds to buy" << endl;
			return false;
		}
	} else {
		return false;
	}
}
		



void Player::receive(int amount) {
	cash += amount;
}


