#include "restaurant.h"
#include <exception>

Restaurant::Restaurant(int c, int p) : capacity(c), remainingSeats(c), prices(p)  {}

//remainingSeats will always be equal to capacity - total customers
int Restaurant::remainingCapacity() const {
	return remainingSeats;
}

int Restaurant::getProfit() const {
	return profit;
}

void Restaurant::addCustomer() {
	if (remainingSeats == 0) {
		throw std::logic_error();
	}

	Patron* p = line.back();
	line.pop_back();
	//customers.push_back(p);
	//the amount of time spent plus the current time will give the time the customer leaves
	waitTimes.insert(std::make_pair(p->getTimeSpent() + currTime, p));
}

//is this necessary? I think so?
int Restaurant::getTime() const {
	return currTime;
}

int Restaurant::tick() {
	currTime++;
	removeCustomers(currTime);
	addCustomer();
}

void Restaurant::removeCustomers(int time) {
	profit += price * waitTimes.count(time);
	waitTimes.erase(time);
}

//can add a Line class to prevent the person getting this from doing stupid crap
list<Patron>& Restaurant::getLine() const {
	return &line;
}

