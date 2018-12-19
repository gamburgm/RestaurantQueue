#include <iostream>
#include <map>
#include <list>
#include <iterator>

using namespace std;

class Venue {
	public:
		virtual int remainingCapacity() const = 0;
		virtual void addCustomer() = 0;
		virtual int getTime() const = 0;
		virtual int getProfit() const = 0;
		virtual void tick() = 0;
		virtual void removeCustomers(int time) = 0;
		virtual list<Patron>& getLine() const = 0;
};
