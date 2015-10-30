/** Triangle.h "Triangle.h"

	The Triangle class implements isosceles triangles by taking the base and height dimensions.
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

namespace Shapes
{
	class Triangle: public Shape
	{
	public:
		Triangle(double base, double height);
		~Triangle();
		virtual const double calculateArea();
		virtual const double calculatePerimeter();
		virtual const ShapeType getType();
		virtual const int getNumSides();

	private:
		const double m_base;
		const double m_height;
	};
};

#endif