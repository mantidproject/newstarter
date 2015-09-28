#include "square.h"



/**
 * Construct this Square.
 *
 * @param type String that represents the type of this shape
 * @param sidecount How many sides a shape of this type has
 */
Square::Square(double sidelength)
	: Shape("Square", 4)
	, m_sideLength(sidelength)
{
	// Empty by design
}

/**
 * Destroy this Square.
 *
 * Virtual to ensure derived types are destroyed correctly when
 * deleted via base class pointer.
 */
Square::~Square()
{
	// Empty by design
}

/**
 * Calculate perimeter of this Square.
 *
 * @return Perimeter of this Square
 */
double Square::calcPerimeter()
{
	return m_sideLength * getSideCount();
}

/**
 * Calculate area of this Square.
 *
 * @return Area of this Square
 */
double Square::calcArea()
{
	return m_sideLength * m_sideLength;
}
