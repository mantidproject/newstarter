/** Rectangle.h "Rectangle.h"

	This Rectangle implements the rectanglular shape by accepting the width and height dimensions. 
	These dimensions are used for calculating the perimeter, area and volume of the rectangle.
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

namespace Shapes
{
	class Rectangle: public Shape
	{
	public:
		Rectangle(double length, double width);
		~Rectangle();
		virtual const double calculateArea();
		virtual const double calculatePerimeter();
		virtual const string getType();
		virtual const int getNumSides();

	protected:
		const double m_length;
		const double m_width;
	};
};

#endif