#include "line.h"

Line::Line() {}

void Line::addPatron() {
	Patron p("", 0, 1);
	line.push_front(p);
}
