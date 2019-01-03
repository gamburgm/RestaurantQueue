#include "restaurant.h"
#include <exception>

pthread_mutex_t forTheLine = PTHREAD_MUTEX_INITIALIZER;

Restaurant::Restaurant(int c, int p) : capacity(c), remainingSeats(c), prices(p)  {
	currTime = 0;
}

//remainingSeats will always be equal to capacity - total customers
int Restaurant::remainingCapacity() const {
	return remainingSeats;
}

int Restaurant::getProfit() const {
	return profit;
}

void Restaurant::addCustomer() {
	if (remainingSeats == 0) {
		throw std::logic_error("cannot add customer when no seats remain");
	}

	if (!line.empty()) {
		//preventing race conditions with adding customers to list and removing them from the list as well
		pthread_mutex_lock( &forTheLine );

		Patron* p = line.back();
		line.pop_back();

		//the amount of time spent plus the current time will give the time the customer leaves
		waitTimes.insert(std::make_pair(p->getTimeSpent() + currTime, p));
		remainingSeats--;

		pthread_mutex_unlock( &forTheLine );
	}
}

//is this necessary? I think so?
int Restaurant::getTime() const {
	return currTime;
}

void Restaurant::tick() {
	currTime++;
	removeCustomers(currTime);
	addCustomer();
}

void Restaurant::removeCustomers(int time) {
	profit += prices * waitTimes.count(time);
	remainingSeats += waitTimes.count(time);

	for (auto it = waitTimes.lower_bound(time); it != waitTimes.upper_bound(time); it++) {
		auto party = (*it).second;
		//printf("The leaving party: %s, %d for %d", party->getName().c_str(), party->getSize(), party->getTimeSpent());
		cout << "Leaving party: " << party->getName() << ", " << party->getSize() << ", for " << party->getTimeSpent() << endl;
		delete party;
	}

	waitTimes.erase(time);
}

void Restaurant::addPatron(string name, int size, int time, bool priority) {
	Patron *p = new Patron(name, size, time);


	if (priority) {
		line.push_back(p);
	} else {
		line.push_front(p);
	}
}



