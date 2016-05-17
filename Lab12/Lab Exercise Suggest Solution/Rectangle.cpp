#include "Rectangle.h"

Rectangle::Rectangle(int w, int h):Polygon(4, w==h? true: false) {
	width = w;
	height = h;

	int sideLengthArray[4] = { w, h, w, h };
	setsideLength(sideLengthArray);
}
void Rectangle::printsideLength() {
	cout << "\tWidth = " << width << ", Height = " << height << endl;
}
int Rectangle::area()
{
	return width * height;
}