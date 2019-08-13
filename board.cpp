#include<bits/stdc++.h>
#include"board.h"

using namespace std;

int randBelow1k() {
	return rand() % 1000;
}

Board::Board(int len, int player_num, bool devMode) {
	// set board's dev mode flag
	dev_mode = devMode;
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
	properties = random_properties(length);
}

// Generate random propteries vector of set length 
vector<Propertys> random_properties(int length) {
	properties = vector<Property>(length);
	for (int i = 0; i < length; ++i) {
		int c = randBelow1k();
		int r = c;
		while (r >= c) r = randBelow1k();
		properties[i] = Property(c, r);
	}

	return properties;
}

// Returns random number between 1 and 6, simulating a dice roll
int Board::single_dice_roll() {
	return (rand() % 6) + 1;
}

// Returns 2 random numbers, each between 1 and 6, added together to simulate two dice rolls
int Board::double_dice_roll() {
	return single_dice_roll() + single_dice_roll();
}

// Basicly a 'round' of the game
void Board::tick() {
	// For each player
	for(Player& player : players) {

		cout << "=== " << player.name << endl;

		// Move player by dice roll
		player.pos = (player.pos + double_dice_roll()) % length;

		// If property is owned
		if (properties[player.pos].owner != NULL) {
			try {
				properties[player.pos].pay_owner(&player);
			} catch (BankruptException& e) {
				cout << player.name << " has gone bankrupt" << endl;
				while (true) {}
			}
		} 

		// If property is unowned
		else {
			// Attempt to buy property
			if (dev_mode) {
				// In dev mode, buy it if theres enough funds
				if (player.voluntary_pay(properties[player.pos].cost)) {
					properties[player.pos].set_owner(&player);
				}
			} else {
				// In play mode, ask player if they should buy it
				if (player.ask_pay(properties[player.pos].cost, properties[player.pos].name)) {
					properties[player.pos].set_owner(&player);
				}
			}
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

