#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double side1, double side2)
	:Shape("Rectangle", 4),
	side1(side1),
	side2(side2)
{
}

double Rectangle::calcArea() const
{
	return side1*side2;
}

double Rectangle::calcPerimeter() const
{
	return side1 * 2 + side2 * 2;
}

void Rectangle::print()
{
	Shape::print();
	cout << ", side 1: " << side1 << ", side 2: " << side2 << endl;
}

Rectangle::~Rectangle()
{
}
