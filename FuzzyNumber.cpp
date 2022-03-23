#include "FuzzyNumber.h"

void FuzzyNumber::display() {
	cout << "{ " << get_x() - get_l()
		<< "; " << get_x()
		<< "; " << get_x() + get_r() << " }" << endl;
}
void FuzzyNumber::read() {
	cout << "x = "; cin >> x;
	cout << "r = "; cin >> r;
	cout << "l = "; cin >> l;
}
void FuzzyNumber::init(double x, double l, double r) {
	set_x(x);
	set_r(r);
	set_l(l);
}

FuzzyNumber sum(FuzzyNumber A, FuzzyNumber B) {
	FuzzyNumber C;
	C.l = A.x + B.x - A.l - B.l;
	C.x = A.x + B.x;
	C.r = A.x + B.x + A.r + B.r;
	return C;
}

FuzzyNumber riz(FuzzyNumber A, FuzzyNumber B) {
	FuzzyNumber C;
	C.l = A.x - B.x - A.l - B.l;
	C.x = A.x - B.x;
	C.r = A.x - B.x + A.r + B.r;
	return C;
}

FuzzyNumber obr(FuzzyNumber A) {
	FuzzyNumber C;
	if (!(A.x > 0)) {
		C.set_x(-1.0);
	}
	else {
		C.set_x(1 / A.get_x());
	}
	C.set_l(1 / (A.get_x() + A.get_r()));
	C.set_r(1 / (A.get_x() - A.get_l()));
	return C;
}

FuzzyNumber div(FuzzyNumber A, FuzzyNumber B) { //A / B = ((xA – lA)/(xB + rB), xA / xB, (xA + rA)/(xB – lB)), xB > 0
	FuzzyNumber C;
	if (!(B.x > 0)) {
		C.x = -1.0;
	}
	else {
		C.x = A.x / B.x;
	}
	C.l = (A.x - A.l) / (B.x + B.r);
	C.r = (A.x + A.r) / (B.x - B.l);
	return C;
}

string FuzzyNumber::ToString() {
	stringstream sout;
	sout << "{ " << get_x() - get_l()
		<< "; " << get_x()
		<< "; " << get_x() + get_r() << " }" << endl;
	return sout.str();
}

