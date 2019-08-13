#include<bits/stdc++.h>
#include"property.h"

struct Board {
	bool dev_mode;
	int length;
	int player_n;
	std::vector<Player> players;
	std::vector<Property> properties;

	Board(int len, int player_num, bool devMode);
	void display();
	int single_dice_roll();
	int double_dice_roll();
	void tick();
};
