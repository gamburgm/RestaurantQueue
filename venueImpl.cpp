#include "venueImpl.h"
#include "venue.h"

VenueImpl::VenueImpl(int c, int p, list<Patron>& l) : capacity(c), prices(p), line(l) {}

int VenueImpl::remainingCapacity() const {
	return capacity - customers.size();
}

void VenueImpl::addCustomer() {
	Patron* p = line.back();
	line.pop_back();
	customers.push_back(p);
	waitTimes.insert(pair<int, Patron> (p->timeSpent, p));

	//lots of issues: is line a pointer to a list? does pop destroy p?
	//do I need to initialize the vector? Am I adding waitTimes correctly?
}

void VenueImpl::removeCustomers(int time) {
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
