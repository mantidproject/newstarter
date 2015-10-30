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
		virtual double calculateArea();
		virtual double calculatePerimeter();

	private:
		double base;
		double height;
	};
};

#endif