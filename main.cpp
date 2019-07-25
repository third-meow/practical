#include<bits/stdc++.h>
#include"board.h"

int main(int argc, char *argv[]) {

	std::srand(std::time(0));

	bool devmode = false;

	if (argc >= 2) {
		for (int i = 0; i < argc; ++i) {
			if (argv[i][1] == 'd') {
				devmode = true;
			}
		}
	}

	Board board(8, 2, devmode); 

	board.display();
	board.tick();
	board.display();

	return 0;
}

