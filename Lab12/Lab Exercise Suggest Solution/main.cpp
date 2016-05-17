// pointers to base class
#include <iostream>
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main() {
	Rectangle rect1(4, 5);
	Rectangle rect2(3, 3);
	Triangle tri(4, 4, false);
	int triLength[3] = { 5, 4, 3 };
	tri.setsideLength(triLength);

	Polygon * p = &rect1;
	cout << "Rectangle 1: " << endl;
	cout << "\tArea: " << p->area() << endl;
	cout << "\tSide: ";
	p->printsideLength();
	rect1.printsideLength();
	cout << "\tTotal Side Length: " << p->totalsideLength() << endl;
	p = &rect2;
	cout << "Rectangle 2: " << endl;
	cout << "\tArea: " << p->area() << endl;
	cout << "\tSide: ";
	p->printsideLength(); 
	rect2.printsideLength();
	cout << "\tTotal Side Length: " << p->totalsideLength() << endl;
	p = &tri;
	cout << "Triangle: " << endl;
	cout << "\tArea: " << p->area() << endl;
	cout << "\tSide: ";
	p->printsideLength(); 
	cout << "\tTotal Side Length: " << p->totalsideLength() << endl;
	system("pause");
	return 0;
}