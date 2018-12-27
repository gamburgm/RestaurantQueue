#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "venue.h"
#include <iostream>
#include <map>

using namespace std;
//could use the decorator pattern to supply the ability to return data about who's visited

//this assumes no cost for providing product
class Restaurant : public Venue {
	public:
		Restaurant(int capacity, int price);
		int remainingCapacity() const;
		int getTime() const;
		int getProfit() const;
		void tick();
		void addPatron(string name, int size, int time, bool priority);
		

	private:
		void addCustomer();
		void removeCustomers(int time);

		const int capacity;
		int remainingSeats;
		multimap<int, Patron*> waitTimes; //I should probably change this
		list<Patron*> line; //could construct it such that the map contains the references/pointers to the vector memory location
		int currTime; //possible that this is unnecessary?
		int prices;  //could be a map, for different products? That could be what's specified by the category of location?
		int profit;
};

#endif
