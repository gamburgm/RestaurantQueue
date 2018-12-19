#include <iostream>
#include <string>

using namespace std;

class Patron {
	public:
		Patron(string party, int s, int time);
		int getTimeSpent() const;
		int getSize() const;
		string getName() const;
		

	private:
		const string nameOfParty;
		const int size;
		const int timeSpent; //should rename
		//what other fields would be useful?
};
