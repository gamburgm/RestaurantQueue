#include <iostream>

using namespace std;

class Venue {
	public:
		Venue() {}
		int remainingCapacity() const = 0;
		//Potential choice: should add customer be a public decision, implying that anyone can add a customer,
		//or should it be private, and should customers be automated?
		void addCustomer() = 0;
		int getTime() const = 0;
		//I'm sure there are probably other operations. Can't think fo them. Maybe operations that involve arguments?
		
};

