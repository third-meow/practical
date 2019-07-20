#include<bits/stdc++.h>
#include"board.h"

using namespace std;

int randBelow1k() {
	return rand() % 1000;
}

Board::Board(int len, int player_num) {
	length = len;
	player_n = player_num;

	players = vector<Player>(player_num);
	for (int i = 0; i < player_n; ++i) {
		players[i] = Player();
		cout << "\t" << players[i].pos;
	}

	properties = vector<Property>(length);
	for (int i = 0; i < length; ++i) {
		int c = randBelow1k();
		int r = c;
		while (r >= c) r = randBelow1k();
		properties[i] = Property(c, r);
	}
}

int Board::diceRoll() {
	double roll = rand() / RAND_MAX;
	return ((int)(roll * 10)) + 2;
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
				cout << " *  |";
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


	//
	// TESTING ONLY
	//
	for (auto player : players) {
		cout << player.pos << endl;
	}
	//
	// TESTING ONLY ENDS
	//
}

