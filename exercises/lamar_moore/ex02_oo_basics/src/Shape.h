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
		virtual double calculateArea()=0;
		virtual double calculatePerimeter()=0;
		virtual ShapeType getType();
		virtual int getNumSides();
	protected:
		int numSides;
		ShapeType type;
	};
};

#endif //SHAPE_H