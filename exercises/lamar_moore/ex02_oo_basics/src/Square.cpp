#include "Square.h"


namespace Shapes
{
	Square::Square(double sideLength): Rectangle(sideLength, sideLength)
	{
		type = ShapeType::SQUARE;
	}

	Square::~Square()
	{
	}
};