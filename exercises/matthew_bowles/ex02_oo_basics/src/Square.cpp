#include "Square.h"

using namespace std;

Square::Square(double side1)
	:Shape("Square", 4),
	side1(side1)
{
}

double Square::calcArea()
{
	return side1*side1;
}

double Square::calcPerimeter()
{
	return side1 * 4;
}

Square::~Square()
{
}
