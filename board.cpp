#include<bits/stdc++.h>
#include"board.h"

using namespace std;

int randBelow1k() {
	return rand() % 1000;
}

Board::Board(int len, int player_num, bool devMode) {
	// set length and number of players
	length = len;
	player_n = player_num;

	// Generate player list
	players = vector<Player>(player_num);
	for (int i = 0; i < player_n; ++i) {
		players[i] = Player();
		if (!devMode) {
			cout << "Player " << i << "'s name: ";
			cin >> players[i].name;
		} else {
			players[i].name = "P-"+to_string(i);
		}
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

int Board::dice_roll() {
	return (rand() % 11) + 2;
}

void Board::tick() {
	for(Player& player : players) {
		player.pos = (player.pos + dice_roll()) % length;
		if (properties[player.pos].owner != NULL) {
			properties[player.pos].pay_owner(&player);
		}
	}
}

int num_places(int n) {
    int r = 1;
    if (n < 0) n = (n == INT_MIN) ? INT_MAX: -n;
    while (n > 9) {
        n /= 10;
        r++;
    }
    return r;
}

string zero_pad(int val, int zero_n) {
	string zeros(zero_n - num_places(val), '0');
	return zeros + to_string(val);
}

string space_pad(string val, int space_n) {
	string spaces(space_n - val.size(), ' ');
	return spaces + val;
}

void Board::display() {
	// Left side ==========================
	vector<string> leftside;
	string line;
	
	// Top Bar ----------------------------
	line = "";
	for (int i = 0; i < length; ++i) {
		line.append("-----");
	}
	leftside.push_back(line);

	// Cost		-----------------------------
	line = "";
	for (int i = 0; i < length; ++i) {
		line.append(zero_pad(properties[i].cost, 4));
		line.append("|");
	}
	leftside.push_back(line);

	// Rent		-----------------------------
	line = "";
	for (int i = 0; i < length; ++i) {
		line.append(zero_pad(properties[i].rent, 4));
		line.append("|");
	}
	leftside.push_back(line);

	// Players ----------------------------
	for (Player& player : players) {
		line = "";
		for (int i = 0; i < length; ++i) {
			if (player.pos == i) {
				line.append(space_pad(player.name, 4));
				line.append("|");
			} else {
				line.append("    |");
			}
		}
		leftside.push_back(line);
	}

	// Bottom Bar -------------------------
	line = "";
	for (int i = 0; i < length; ++i) {
		line.append("-----");
	}
	leftside.push_back(line);

	// Right side =========================
	vector<string> rightside;

	for (Player& player : players) {
		rightside.push_back(player.name + ":");
		// Cash ----------------------------
		rightside.push_back("Cash: " + to_string(player.cash));
	}

	// Render =============================
	
	// Calculate longest line on leftside
	int left_side_max = 0;
	for (auto line : leftside)
		left_side_max = max(left_side_max, (int) line.size());
	
	string blank(left_side_max, ' ');
	while(leftside.size() < rightside.size()) {
		leftside.push_back(blank);
	}
	
	for (int i = 0; i < leftside.size(); ++i) {
		cout << leftside[i];
		if (rightside.size() > i) cout << "  " << rightside[i];
		cout << endl;
	}
}

