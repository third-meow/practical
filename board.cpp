#include<bits/stdc++.h>
#include"board.h"

using namespace std;

int randBelow1k() {
	return rand() % 1000;
}

Board::Board(int len, int player_num) {
	// set length and number of players
	length = len;
	player_n = player_num;

	// Generate player list
	players = vector<Player>(player_num);
	for (int i = 0; i < player_n; ++i) {
		players[i] = Player();
		cout << "Player " << i << "'s name: ";
		cin >> players[i].name;
	}

	// Generate property list
	properties = vector<Property>(length);
	for (int i = 0; i < length; ++i) {
		int c = randBelow1k();
		int r = c;
		while (r >= c) r = randBelow1k();
		properties[i] = Property(c, r);
	}
}

int Board::diceRoll() {
	return (rand() % 11) + 2;
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
	// Top bar	---------------------------
	for (int i = 0; i < length; ++i) {
		cout << "-----";
	}
	cout << endl;

	// Cost		-----------------------------
	for (int i = 0; i < length; ++i) {
		cout << setw(4) << properties[i].cost << "|";
	}
	cout << endl;

	// Rent		-----------------------------
	for (int i = 0; i < length; ++i) {
		cout << setw(4) << properties[i].rent << "|";
	}
	cout << endl;

	// Players
	for (Player& player : players) {
		for (int i = 0; i < length; ++i) {
			if (player.pos == i) {
				cout << setw(4) << player.name << "|";
			} else {
				cout << "    |";
			}
		}
		cout << endl;
	}


	// Bottom bar		-----------------------
	for (int i = 0; i < length; ++i) {
		cout << "-----";
	}
	cout << endl;

}

