#ifndef SHAPE_H
#define SHAPE_H

namespace Shapes
{
	/** List of possible shape types.
	*/
	typedef enum
	{
		SQUARE = 0,
		RECTANGLE = 1,
		CIRCLE = 2,
		TRIANGLE = 3
	}ShapeType;

	/** Shape Shape.h "Shape.h"
		
		Base interface for all shape types. This includes methods for calculating the perimeter, area
		and volume of shapes.
	*/
	class Shape
	{
	public:
		virtual const double calculateArea()=0;
		virtual const double calculatePerimeter()=0;
		virtual const ShapeType getType()=0;
		virtual const int getNumSides()=0;
	};
};

#endif //SHAPE_H