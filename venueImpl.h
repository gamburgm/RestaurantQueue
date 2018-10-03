#include <iostream>
#include <map>
#include <list>
#include <iterator>
#include "venue.h"

using namespace std;

class VenueImpl : public Venue {
	public:
		VenueImpl(int c, int p, list<Patron>& l); //prices could be a map?
		int remainingCapacity() const;
		void addCustomer();
		int getTime() const;
		void setLine(list<Patron>& l); //should this be an interface function?

	private:
		const int capacity;
		unordered_multimap<int, Patron> waitTimes; //I should probably change this
		list<Patron> line; //could construct it such that the map contains the references/pointers to the vector memory location
		vector<Patron> customers;
		int currTime; //possible that this is unnecessary?
		int prices;  //could be a map, for different products? That could be what's specified by the category of location?
};
