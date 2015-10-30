/** Circle.h "Circle.h"

	The Circle class implements circular shapes by taking the radius.
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

namespace Shapes
{
	class Circle: public Shape
	{
	public:
		Circle(double radius);
		~Circle();
		virtual const double calculateArea();
		virtual const double calculatePerimeter();
		virtual const string getType();
		virtual const int getNumSides();

	private:
		const double m_radius;
	};

	static const double PI = 3.14159265359;
};

#endif