#include<bits/stdc++.h>
#include"board.h"

int main(int argc, char *argv[]) {

	std::srand(std::time(0));

	bool devmode = false;
	std::string board_file_path;

	if (argc >= 2) {
		for (int i = 0; i < argc; ++i) {
			if (argv[i][0] == '-') {
				if (argv[i][1] == 'd') {
					devmode = true;
				} else if (argv[i][1] == 'b') {
					board_file_path = argv[++i];
				}
			}
		}
	}

	std::cout << "Board file path: " << board_file_path << std::endl;
	Board board(0, 0, true);
	if (board_file_path.empty()) {
		board = Board(board_file_path, 2, devmode); 
	} else {
		board = Board(8, 2, devmode); 
	}


	board.display();
	while (true) {
		board.tick();
		board.display();
	}

	return 0;
}

