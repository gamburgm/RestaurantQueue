#include <iostream>
#include <list>

class Line {
	public:
		Line();
		void addPatron();  //could, in theory, return a patron so that an external thing could take note
		
	private:
		list<Patron> line;
};
