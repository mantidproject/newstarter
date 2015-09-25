#include "triangle.h"

// Required for pow() and sqrt()
#include <math.h>



/**
 * Construct this Triangle.
 *
 * @param type String that represents the type of this shape
 * @param sidecount How many sides a shape of this type has
 */
Triangle::Triangle(double height, double base)
	: Shape("Triangle", 3)
	, m_height(height)
	, m_base(base)
{
	// Empty by design
}

/**
 * Destroy this Triangle.
 *
 * Virtual to ensure derived types are destroyed correctly when
 * deleted via base class pointer.
 */
Triangle::~Triangle()
{
	// Empty by design
}

/**
 * Calculate perimeter of this Triangle.
 *
 * @return Perimeter of this Triangle
 */
double Triangle::calcPerimeter()
{
	return m_base + (2 * sqrt(pow(m_height, 2) + (pow(m_base, 2) / 4)));
}

/**
 * Calculate area of this Triangle.
 *
 * @return Area of this Triangle
 */
double Triangle::calcArea()
{
	return m_height * (m_base / 2);
}
