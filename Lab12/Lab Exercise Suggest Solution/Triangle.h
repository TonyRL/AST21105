#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h"

class Triangle : public Polygon {
private:
	int width;
	int height;
public:
	Triangle(int w, int h, bool s = false);
	int area();
};
#endif // !TRIANGLE_H
