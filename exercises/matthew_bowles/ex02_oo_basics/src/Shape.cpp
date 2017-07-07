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

double Shape::calcArea()
{
	return 0;
}

double Shape::calcPerimeter()
{
	return 0;
}

Shape::~Shape()
{
}

