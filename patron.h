#include <iostream>
#include <string>

using namespace std;

class Patron {
	public:
		Patron(string party, int s, int time);
		//tbh what functions would be useful? What would somebody want to know about Patrons?

	private:
		const string nameOfParty;
		const int size;
		const int timeSpent; //should rename
		//what other fields would be useful?
};
