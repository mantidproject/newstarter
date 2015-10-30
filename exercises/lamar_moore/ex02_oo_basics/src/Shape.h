#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

namespace Shapes
{
	/** Shape Shape.h "Shape.h"
		
		Base interface for all shape types. This includes methods for calculating the perimeter, area
		and volume of shapes.
	*/
	class Shape
	{
	public:
		virtual const double calculateArea()=0;
		virtual const double calculatePerimeter()=0;
		virtual const string getType()=0;
		virtual const int getNumSides()=0;
	};
};

#endif //SHAPE_H