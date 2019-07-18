#include<bits/stdc++.h>
#include"property.h"

class Board {
	public:
		int length;
		std::vector<Property> properties;
		Board();
		Board(int len);
		void display();
};
