#include "patron.h"

using namespace std;

Patron::Patron(string party, int s, int time) {
	nameOfParty = party;
	size = s;
	timeSpent = time;
}

int Patron::getTimeSpent() const {
	return timeSpent;
}

int Patron::getSize() const {
	return size;
}

string Patron::getName() const {
	return nameOfParty;
}
	
