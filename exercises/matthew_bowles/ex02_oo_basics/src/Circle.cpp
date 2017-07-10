#include "Circle.h"

using namespace std;

Circle::Circle(double radius)
	:Shape("Circle", 1),
	radius(radius)
{
}

double Circle::calcArea() const
{
	return M_PI * radius * radius;
}

double Circle::calcPerimeter() const
{
	return M_PI * radius * 2;
}

void Circle::print()
{
	Shape::print();
	cout << ", radius: " << radius << endl;
}

Circle::~Circle()
{
}
