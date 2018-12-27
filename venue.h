#ifndef VENUE_H
#define VENUE_H

#include <list>
#include "patron.h"

using namespace std;

class Venue {
	public:
		virtual int remainingCapacity() const = 0;
		virtual int getTime() const = 0;
		virtual int getProfit() const = 0;
		virtual void tick() = 0;
		virtual void addPatron(string name, int size, int time, bool priority) = 0;
};

#endif
