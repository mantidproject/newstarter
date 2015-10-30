#include "Shape.h"


namespace Shapes
{
	/** Returns the shape type
	*/
	ShapeType Shape::getType()
	{
		return type;
	}

	/** Returns the number of sides 
	*/
	int Shape::getNumSides()
	{
		return numSides;
	}
};