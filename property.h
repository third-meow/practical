#include"player.h"

class Property {
	public:
	int cost;
	int rent;
	int house_val;
	Player* owner;

	Property();
	Property(int cst, int rnt);
	void setOwner(Player* newOwner);
	void payOwner(Player* guest);
};


