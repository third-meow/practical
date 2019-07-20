#include<bits/stdc++.h>
#include"property.h"

struct Board {
	int length;
	int player_n;
	std::vector<Player> players;
	std::vector<Property> properties;

	Board(int len, int player_num);
	void display();
	int diceRoll();
	void tick();
};
