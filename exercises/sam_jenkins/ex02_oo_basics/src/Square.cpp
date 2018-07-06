#include "Shapes.h"
#include "Square.h"
	Square::Square() :side(1) 
	{
		type = "Square";
		sides = 4;
	}
	Square::Square(double side):side(side)
	{
		type = "Square";
		sides = 4;
	}
	double Square::calcPerimiter()const {
		return 4 * side;
	}
	double Square::calcArea()const {
		return side*side;
	}