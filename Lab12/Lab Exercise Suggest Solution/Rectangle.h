#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Polygon.h"

class Rectangle : public Polygon {
private:
	int width;
	int height;
public:
	Rectangle(int w, int h);
	void printsideLength();
	int area();
};

#endif // !RECTANGLE_H



