#include<exception>
#include<bits/stdc++.h>

struct BankruptException : public std::exception {
	const char * what () const throw () {
		return "Player has gone bankrupt";
	}
};

struct Player {
	std::string name;
	int pos;
	int cash;

	Player();
	void pay(int amount);
	bool voluntary_pay(int amount);
	bool ask_pay(int amount, std::string property_name);
	void receive(int amount);

};
