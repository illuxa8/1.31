#include <iostream>
#include <string>
#include <sstream>
#include "FuzzyNumber.h"

using namespace std;

int main() {
	FuzzyNumber a;
	FuzzyNumber b;
	FuzzyNumber c;

	a.init(3, 1.5, 2);
	b.read();
	a.display();
	b.display();

	c = sum(a, b);
	c.display();
	cout << c.ToString();

	c = riz(a, b);
	c.display();

	c = obr(a);
	c.display();

	c = div(a, b);
	c.display();

	return 0;
}
