#include "Triangle.h"

using namespace std;

Triangle::Triangle(double base, double height)
	:Shape("Triangle", 3),
	base(base),
	height(height)
{
}

double Triangle::calcArea()
{
	return height * base / 2;
}

double Triangle::calcPerimeter()
{
	return base + 2*(sqrt(height * height + (base * base / 4)));
}

void Triangle::print()
{
	Shape::print();
	cout << ", base: " << base << ", height: " << height << endl;
}

string Triangle::getType()
{
	return "Triangle";
}

Triangle::~Triangle()
{
}
