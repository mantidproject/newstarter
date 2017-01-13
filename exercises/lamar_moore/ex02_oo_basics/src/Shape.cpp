#include "Shape.h"


namespace Shapes
{
	/** Returns the shape type
	*/
	const ShapeType Shape::getType()
	{
		return type;
	}

	/** Returns the number of sides 
	*/
	const int Shape::getNumSides()
	{
		return numSides;
	}
};