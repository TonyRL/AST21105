#include "Polygon.h"

Polygon::Polygon() {
	noOfSide = 3;
	isAllSideEqual = false;
	sideLength = new int[noOfSide];
};

Polygon::Polygon(int n, bool s) {
	if (n < 3) {
		n = 3;
	}
	noOfSide = n;
	isAllSideEqual = s;
	sideLength = new int[noOfSide];
}
Polygon::~Polygon() {
	delete[] sideLength;
}
void Polygon::setsideLength(int* sl) {
	for (int i = 0; i < noOfSide; ++i) {
		sideLength[i] = sl[i];
	}
}
void Polygon::printsideLength() {
	for (int i = 0; i < noOfSide; ++i) {
		cout << sideLength[i] << " ";
	}
	cout << endl;
}
int Polygon::totalsideLength() {
	int result = 0;
	for (int i = 0; i < noOfSide; ++i) {
		result += sideLength[i];
	}
	return result;
}
int Polygon::area() {
	return 0;
}