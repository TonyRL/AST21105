#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
using namespace std;

class Polygon {
private:
	int noOfSide;
	bool isAllSideEqual;
	int* sideLength;
public:
	Polygon();
	Polygon(int n, bool s = false);
	~Polygon();
	void setsideLength(int* sl);
	void printsideLength();
	int totalsideLength();
	virtual int area();
};

#endif // !POLYGON_H