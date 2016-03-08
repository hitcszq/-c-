#include <iostream>
#include "polynomial.h"
#include "dataclass.h"
using namespace std;
int main(){
	//data terms1[] = { { 1, 2 }, { 3, 7 }, { 6, 5 } };
	//data terms2[] = { { 2, 5 }, { 3, 6 }, { 7, 4 } };
	//data terms1[] = new terms[3];
	//data terms1[0] = data(1, 2);
	const int STKS = 3;
	dataclass terms1[STKS] = {
		dataclass(1, 2),
		dataclass(3, 7),
		dataclass(6, 5),
	};
	dataclass terms2[STKS] = {
		dataclass(2, 5),
		dataclass(3, 6),
		dataclass(7, 4),
	};
	Polynomial poly1 = Polynomial(terms1, 3);
	Polynomial poly2 = Polynomial(terms2, 3);
	Polynomial poly = Polynomial();
	poly= poly2+poly1;
	return 0;
}