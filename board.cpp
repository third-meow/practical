#include<bits/stdc++.h>
#include"board.h"

int randBelow1k() {
	return rand() % 1000;
}

Board::Board() {
	Board(4);
}

Board::Board(int len) {
	length = len;

	properties = std::vector<Property>(length, Property());

	//
	// TESTING ONLY
	//
	for (int i = 0; i < length; ++i) {
		int c = randBelow1k();
		int r = c;
		while (r >= c) r = randBelow1k();
		properties[i] = Property(c, r);
	}
	//
	// TESTING ONLY ENDS
	//

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
