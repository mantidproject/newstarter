//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Triangle.h"

/*
 * Constructs a new isoceles triangle with the specified height and base
 * length.
 *
 * @param height	The height of the triangle to construct.
 *
 * @param base		The length of the base of the triangle to
 *                  construct.
 */
Triangle::Triangle(double height, double base) {

	if (height < 0) {
		std::ostringstream ss;
		ss << "Height of a " << name() << " must be greater than or equal to 0.";
		throw std::invalid_argument(ss.str());
	}
	else if (base < 0) {
		std::ostringstream ss;
		ss << "Base length of a " << name() << " must be greater than or equal to 0.";
		throw std::invalid_argument(ss.str());
	}
	m_height = height;
	m_base = base;
}

/*
 * Destructor for this triangle.
 */
Triangle::~Triangle() {
}

/*
 * Perimeter is calculated using the formula:
 * base + 2 * sqrt(height^2 + (base ^ 2)/4) 
 *
 * @return	The perimeter of this triangle.
 */
double Triangle::perimeter() const {
	return m_base + 2 * sqrt(m_height * m_height + (m_base*m_base) / 4);
}

/*
 * Area is calculate using the formula:
 * height * base / 2
 *
 * @return	The area of this triangle.
 */
double Triangle::area() const {
	return m_height * m_base / 2;
}

/*
 * @return	The name of this triangle.
 */
std::string Triangle::name() const {
	return "Triangle";
}

/*
 * @return	The number of sides this triangle has.
 */
int Triangle::numberOfSides() const {
	return 3;
}

/* 
 * @return	The string representation of this triangle.
 */
std::string Triangle::toString() const {
	std::ostringstream ss;
	ss << "Triangle | Height: " << m_height << ", Base: " << m_base;
	return ss.str();
}