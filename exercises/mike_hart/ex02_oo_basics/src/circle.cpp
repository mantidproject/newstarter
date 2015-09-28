#include "circle.h"

// Required for M_PI constant
#define _USE_MATH_DEFINES
#include <math.h>



/**
 * Construct this Circle.
 *
 * @param type String that represents the type of this shape
 * @param sidecount How many sides a shape of this type has
 */
Circle::Circle(double radius)
	: Shape("Circle", 1)
	, m_radius(radius)
{
	// Empty by design
}

/**
 * Destroy this Circle.
 *
 * Virtual to ensure derived types are destroyed correctly when
 * deleted via base class pointer.
 */
Circle::~Circle()
{
	// Empty by design
}

/**
 * Calculate perimeter of this Circle.
 *
 * @return Perimeter of this Circle
 */
double Circle::calcPerimeter()
{
	return 2 * M_PI * m_radius;
}

/**
 * Calculate area of this Circle.
 *
 * @return Area of this Circle
 */
double Circle::calcArea()
{
	return M_PI * m_radius * m_radius;
}
