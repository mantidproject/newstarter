//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Shape.h"

/*
 * Constructs a new Shape with the specified name and number
 * of sides.
 *
 * @param name		The name of the shape to construct.
 *
 * @param numSides	The number of sides of the shape to construct.
 */
Shape::Shape(std::string name, int numSides) : m_name(name), m_numSides(numSides) {
}

/*
 * Destructor for this Shape.
 */
Shape::~Shape() {
}

/*
 * @return	The name of this shape.
 */
std::string Shape::getName() const {
	return m_name;
}

/*
 * @return	The number of sides this shape has.
 */
int Shape::numberOfSides() const {
	return m_numSides;
}