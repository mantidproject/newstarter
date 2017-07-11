//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Square.h"

/*
 * Constructs a new Square of the specified size.
 *
 * @param size				The size of the Square to construct.
 *
 * @throw invalid_argument	Thrown when the specified size is less
 *							than 0.
 */
Square::Square(double size) 
	: Rectangle(size, size) {
	m_size = size;
}

/*
 * @return	The type of this square.
 */
ShapeType Square::type() const {
	return ShapeType::Square;
}

/*
 * @return	The name of this square.
 */
std::string Square::name() const {
	return "Square";
}

/*
 * @return	The string representation of this square.
 */
std::string Square::toString() const {
	return "Square | Size: " + std::to_string(m_size);
}