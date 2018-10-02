#include <iostream>
#include <map>
#include <list>
#include <iterator>
#include "venue.h"

using namespace std;

class VenueImpl : public Venue {
	public:
		int remainingCapacity() const;
		void addCustomer();
		int getTime() const;

	private:
		const int capacity;
		unordered_multimap<int, Patron> waitTimes; //I should probably change this
		list<Patron> line;
		vector<Patron> customers;
		int time;
		//int curr time
		//list
		//curr capacity?
		//have regular container for all people and have values be pointers to Patrons 

};
