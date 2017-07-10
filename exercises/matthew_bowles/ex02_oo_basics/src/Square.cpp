#include "Square.h"

using namespace std;

Square::Square(double side1)
	:Shape("Square", 4),
	side1(side1)
{
}

double Square::calcArea() const
{
	return side1*side1;
}

double Square::calcPerimeter() const
{
	return side1 * 4;
}

void Square::print()
{
	Shape::print();
	cout << ", side: " << side1 << endl;
}

Square::~Square()
{
}
