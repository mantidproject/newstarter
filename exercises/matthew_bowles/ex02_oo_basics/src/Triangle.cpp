#include "Triangle.h"

Triangle::Triangle(double base, double height)
	:Shape("Triangle", 3),
	base(base),
	height(height)
{
}

double Triangle::calcArea() const
{
	return height * base / 2;
}

double Triangle::calcPerimeter() const
{ 
	return base + 2*(sqrt(height * height + (base * base / 4)));
}

void Triangle::print() const
{
	Shape::print();
	std::cout << ", base: " << base << ", height: " << height << std::endl;
}

Triangle::~Triangle()
{
}
