#include "circle.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Construct a new Circle with given radius.
 * \param radiusIn Radius of the circle.
 */
Circle::Circle(double radiusIn) : Shape(1, "Circle")
{
	radius = radiusIn;
}

/**
 * \brief Calculates the perimeter of this circle.
 * \returns Perimeter of the circle.
 */
double Circle::perimeter() const
{
	return 2.0 * M_PI * radius;
}

/**
 * \brief Calculates the area of this circle.
 * \returns Area of the circle.
 */
double Circle::area() const
{
	return M_PI * radius * radius;
}
