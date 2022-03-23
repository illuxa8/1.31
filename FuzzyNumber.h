#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FuzzyNumber
{
private:
	double x;
	double l;
	double r;
public:
	void set_x(double a) { x = a; }
	void set_l(double a) { l = a; }
	void set_r(double a) { r = a; }

	double get_x() { return x; }
	double get_l() { return l; }
	double get_r() { return r; }

	void display();
	void read();
	void init(double x, double l, double r);

	friend FuzzyNumber sum(FuzzyNumber A, FuzzyNumber B);
	friend FuzzyNumber riz(FuzzyNumber A, FuzzyNumber B);
	friend FuzzyNumber obr(FuzzyNumber A);
	friend FuzzyNumber div(FuzzyNumber A, FuzzyNumber B);

	string ToString();
};
