#include "venue.h"

Venue::Venue(int c, int p, list<Patron>& l) : capacity(c), prices(p), line(l) {}

int Venue::remainingCapacity() const {
	return capacity - customers.size();
}

void Venue::addCustomer() {
	Patron* p = line.back();
	line.pop_back();
	customers.push_back(p);
	//not sure if this is the way I want to handle this?
	waitTimes.insert(pair<int, Patron> (p->timeSpent, p));

	//lots of issues: is line a pointer to a list? does pop destroy p?
	//do I need to initialize the vector? Am I adding waitTimes correctly?
}

void Venue::removeCustomers(int time) {
	//need to save the patron values somehow to return or transmit somehow to external thread?
	//is the external thread actually necessary? How does it even get implmeneted?
	//I can worry about that later.
	waitTimes.erase(time);
}

//is this necessary? I think so?
int getTime() const {
	return 0;
}

//should this be a thing?
void setLine(list<Patron>& l) {
	line = l;
}
