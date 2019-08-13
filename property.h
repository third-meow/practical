#include"player.h"

struct Property {
	std::string name = "<no name yet>";
	int cost;
	int rent;
	int house_val;
	Player* owner;

	Property();
	Property(int cst, int rnt);
	void set_owner(Player* new_owner);
	void pay_owner(Player* guest);
};


