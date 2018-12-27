#include "controller.h"

Controller::Controller(istream *i, ostream *o, Venue *v) : input(i), output(o), venue(v) {
}

void Controller::play() {
	while ((*input).good()) {
		string partyName;
		int size, time;
		//perhaps I want a less stupid introduction
		//perhaps I should also do some refactoring here
		(*output) << "Please produce a Patron: string party, int size, int time" << endl;

		(*input) >> partyName;
		(*input) >> size >> time;

		venue->addPatron(partyName, size, time, false);
	}
}

