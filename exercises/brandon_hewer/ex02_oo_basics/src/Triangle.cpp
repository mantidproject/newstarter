//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Triangle.h"

/*
 * Constructs a new isoceles triangle with the specified height and base
 * length.
 *
 * @param height			The height of the triangle to construct.
 * @param base				The length of the base of the triangle to
 *							construct.
 *
 * @throw invalid_argument	Thrown when the specified heigth or base length
 *							is less than 0.
 */
Triangle::Triangle(double height, double base) {

	if (height < 0) {
		std::string errorMsg = "Height of a " + name() + " must be greater than or equal to 0.";
		throw std::invalid_argument(errorMsg);
	}
	else if (base < 0) {
		std::string errorMsg = "Base length of a " + name() + " must be greater than or equal to 0.";
		throw std::invalid_argument(errorMsg);
	}

	m_height = height;
	m_base = base;
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
ShapeType Triangle::type() const {
	return ShapeType::Triangle;
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
	return "Triangle | Height: " + std::to_string(m_height) +
		", Base: " + std::to_string(m_base);
}