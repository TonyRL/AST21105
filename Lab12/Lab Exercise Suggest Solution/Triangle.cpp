#include "Triangle.h"

Triangle::Triangle(int w, int h, bool s) : width(w), height(h), Polygon(3, s) {}

int Triangle::area()
{
	return width*height / 2;
}