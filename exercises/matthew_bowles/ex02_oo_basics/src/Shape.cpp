#include "Shape.h"

using namespace std;

Shape::Shape()
{
}

Shape::Shape(string type, int sideCount)
	:shapeType(type),
	sideCount(sideCount)
{
}

string Shape::getType()
{
	return shapeType;
}

double Shape::calcArea() const
{
	return 0;
}

double Shape::calcPerimeter() const
{
	return 0;
}

void Shape::print()
{
	cout << "Type: " << shapeType << ", sides: " << sideCount;
}

Shape::~Shape()
{
}

