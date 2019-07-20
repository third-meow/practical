#include<bits/stdc++.h>
#include"property.h"

Property::Property() {
	Property(0, 0);
}

Property::Property(int cst, int rnt) {
	cost = cst;
	rent = rnt;
	house_val = 1;
	owner = NULL;
}

void Property::setOwner(Player* newOwner) {
	owner = newOwner;
}

void Property::payOwner(Player* guest) {
	guest->cash -= rent;
	owner->cash += rent;
}
