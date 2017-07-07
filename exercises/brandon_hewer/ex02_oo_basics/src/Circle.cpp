//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Circle.h"

/*
 * Constructs a new Circle with the specified radius.
 *
 * @param radius	The radius of the circle to construct.
 *
 * @throw invalid_argument	Thrown if specified radius is less than zero.
 */
Circle::Circle(double radius) {
	
	if (radius < 0) {
		std::ostringstream ss;
		ss << "Radius of a " << name() << " must be greater than or equal"
			"to 0";
		throw std::invalid_argument(ss.str());
		m_radius = radius;
	}
	m_radius = radius;
}

/*
 * Destructor for this circle.
 */
Circle::~Circle() {
}

/*
 * Perimeter of this circle is calculated using:
 * 2 * PI * radius
 *
 * @return	The perimeter of this circle.
 */
double Circle::perimeter() const {
	return 2 * M_PI * m_radius;
}

/*
 * Area of this circle is calculated using:
 * PI * radius^2
 *
 * @return	The area of this circle.
 */
double Circle::area() const {
	return M_PI * m_radius * m_radius;
}

/*
 * @return	The name of this circle.
 */
std::string Circle::name() const {
	return "Circle";
}

/*
 * @return	The number of sides this circle has.
 */
int Circle::numberOfSides() const {
	return 1;
}

/*
 * @return	The string representation of this circle.
 */
std::string Circle::toString() const {
	std::ostringstream ss;
	ss << "Circle | Radius: " << m_radius;
	return ss.str();
}