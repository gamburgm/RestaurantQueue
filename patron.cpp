#include "patron.h"

using namespace std;

Patron::Patron(string p, int s, int t) : nameOfParty(p), size(s), timeSpent(t) {}

int Patron::getTimeSpent() const {
	return timeSpent;
}

int Patron::getSize() const {
	return size;
}

string Patron::getName() const {
	return nameOfParty;
}
	
