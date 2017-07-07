//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Square.h"

/*
 * Constructs a new Square of the specified size.
 *
 * @param size	The size of the Square to construct.
 */
Square::Square(double size) 
	: Rectangle(size, size) {
	m_size = size;
}

/*
 * Destructor for this Square.
 */
Square::~Square(){
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
	std::ostringstream ss;
	ss << "Square | Size: " << m_size;
	return ss.str();
}