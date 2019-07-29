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

void Property::set_owner(Player* new_owner) {
	owner = new_owner;
}

void Property::pay_owner(Player* guest) {
	guest->pay(rent);
	owner->receive(rent);
}
