#include<bits/stdc++.h>
#include"property.h"

class Board {
	public:
		int length;
		int player_n;
		std::vector<Player> players;
		std::vector<Property> properties;

		Board(int len, int player_num);
		void display();
		int diceRoll();
		void tick();
};
