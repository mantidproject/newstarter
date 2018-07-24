#include "Shapes.h"
#include "Square.h"
	Square::Square() :Shapes("Square", 4), length(1)
	{

	}
	Square::Square(double side) :Shapes("Square", 4), length(side)
	{

	}
	double Square::calcPerimiter()const {
		return getSides() * length;
	}
	double Square::calcArea()const {
		return length*length;
	}