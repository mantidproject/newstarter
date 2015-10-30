#include "Square.h"


namespace Shapes
{
	Square::Square(double sideLength): Rectangle(sideLength, sideLength)
	{
	}

	Square::~Square()
	{
	}

	const string Square::getType()
	{
		return "Square";
	}
};