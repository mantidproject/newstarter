#include "Shapes.h"
#include "Square.h"
	Square::Square() :Shapes("Square", 4), side(1)
	{

	}
	Square::Square(double side) :Shapes("Square", 4), side(side)
	{

	}
	double Square::calcPerimiter()const {
		return 4 * side;
	}
	double Square::calcArea()const {
		return side*side;
	}