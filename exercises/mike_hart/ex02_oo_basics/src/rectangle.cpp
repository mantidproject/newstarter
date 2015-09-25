#include "rectangle.h"



/**
 * Construct this Rectangle.
 *
 * @param type String that represents the type of this shape
 * @param sidecount How many sides a shape of this type has
 */
Rectangle::Rectangle(double side1, double side2)
	: Shape("Rectangle", 4)
	, m_sideLength1(side1)
	, m_sideLength2(side2)
{
	// Empty by design
}

/**
 * Destroy this Rectangle.
 *
 * Virtual to ensure derived types are destroyed correctly when
 * deleted via base class pointer.
 */
Rectangle::~Rectangle()
{
	// Empty by design
}

/**
 * Calculate perimeter of this Rectangle.
 *
 * @return Perimeter of this Rectangle
 */
double Rectangle::calcPerimeter()
{
	return (m_sideLength1 * 2) + (m_sideLength2 * 2);
}

/**
 * Calculate area of this Rectangle.
 *
 * @return Area of this Rectangle
 */
double Rectangle::calcArea()
{
	return m_sideLength1 * m_sideLength2;
}
