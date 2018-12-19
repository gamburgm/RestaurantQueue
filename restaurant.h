#include "venue.h"

using namespace std;
//could use the decorator pattern to supply the ability to return data about who's visited

//this assumes no cost for providing product
class Restaurant : public Venue {
	public:
		Restaurant(int capacity, int price);
		int remainingCapacity() const;
		int getTime() const;
		list<Patron>& getLine() const;
		int getProfit() const;
		void tick();
		void removeCustomers(int time);
		void addCustomer();

	private:
		const int capacity;
		int remainingSeats;
		unordered_multimap<int, Patron> waitTimes; //I should probably change this
		list<Patron> line; //could construct it such that the map contains the references/pointers to the vector memory location
		//vector<Patron> customers;
		int currTime; //possible that this is unnecessary?
		int prices;  //could be a map, for different products? That could be what's specified by the category of location?
		int profit;
};
