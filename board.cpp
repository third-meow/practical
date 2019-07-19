#include<bits/stdc++.h>
#include"board.h"

int randBelow1k() {
	return rand() % 1000;
}

Board::Board(int len, int player_num) {
	length = len;
	player_n = player_num;

	players = std::vector<Player>(player_num, Player());
	properties = std::vector<Property>(length, Property(0,0));

	//
	// TESTING ONLY
	//
	for (int i = 0; i < length; ++i) {
		int c = randBelow1k();
		int r = c;
		while (r >= c) r = randBelow1k();
		properties[i].cost = c;
		properties[i].rent = r;
	}
	//
	// TESTING ONLY ENDS
	//

}


int Board::diceRoll() {
	return 3;
}

void Board::tick() {
	for(Player& player : players) {
		player.pos = (player.pos + diceRoll()) % length;
		if (properties[player.pos].owner != NULL) {
			properties[player.pos].payOwner(&player);
		}
	}




}

void Board::display() {
	for (int i = 0; i < length; ++i) {
		std::cout << "-----";
	}
	std::cout << std::endl;

	for (int i = 0; i < length; ++i) {
		std::cout << std::setw(4) << properties[i].cost << "|";
	}
	std::cout << std::endl;

	for (int i = 0; i < length; ++i) {
		std::cout << std::setw(4) << properties[i].rent << "|";
	}
	std::cout << std::endl;

	for (int i = 0; i < length; ++i) {
		std::cout << "-----";
	}
	std::cout << std::endl;
}
