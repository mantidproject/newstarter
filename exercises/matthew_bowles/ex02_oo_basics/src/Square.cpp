#include "Square.h"

Square::Square(double side)
	:Shape("Square", 4),
	side(side)
{
}

double Square::calcArea() const
{
	return side*side;
}

double Square::calcPerimeter() const
{
	return side * 4;
}

void Square::print() const
{
	Shape::print();
	std::cout << ", side: " << side << '\n';
}

Square::~Square()
{
}
