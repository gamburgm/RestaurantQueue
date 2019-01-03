#include "venue.h"
#include "mutexes.h"
#include <iostream>

class Controller {
	public:
		Controller(istream *i, ostream *o, Venue *v);
		void play();
	private:
		istream *input;
		ostream *output;
		Venue *venue;
};
