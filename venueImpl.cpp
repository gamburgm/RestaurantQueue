#include "venueImpl.h"
#include "venue.h"

VenueImpl::VenueImpl(int c, int p, list<Patron>& l) : capacity(c), prices(p), line(l) {}

int VenueImpl::remainingCapacity() const {
	return capacity - customers.size();
}

void VenueImpl::addCustomer() {
	//get top item off linked list
	//add to vector and multimap	
}

//is this necessary? I think so?
int getTime() const {
	return 0;
}

//should this be a thing?
void setLine(list<Patron>& l) {
	line = l;
}
