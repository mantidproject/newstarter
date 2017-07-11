//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Rectangle.h"

#include <stdexcept>

/*
 * Constructs a new rectangle of the specified width and height.
 *
 * @param width				The width of the rectangle to construct.
 * @param height			The height of the rectangle to construct.
 *
 * @throw invalid_argument	Thrown when specified width or height
 *							is less than 0.
 */
Rectangle::Rectangle(double width, double height) {

	if (width < 0) {
		std::string errorMsg = "Width of a " + name() + " must be greater than or equal to 0.";
		throw std::invalid_argument(errorMsg);
	}
	else if (height < 0) {
		std::string errorMsg = "Height of a " + name() + " must be greater than or equal to 0.";
		throw std::invalid_argument(errorMsg);
	}

	m_width = width;
	m_height = height;
}

/*
 * Perimeter of this rectangle is calculated using:
 * (width * 2) + (height * 2)
 *
 * @return	The perimeter of this rectangle.
 */
double Rectangle::perimeter() const {
	return m_width * 2 + m_height * 2;
}

/*
 * Area of this rectangle is calculated using:
 * width * height
 *
 * @return	The area of this triangle.
 */
double Rectangle::area() const {
	return m_width * m_height;
}

/*
 * @return	The type of this rectangle.
 */
ShapeType Rectangle::type() const {
	return ShapeType::Rectangle;
}

/*
 * @return	The name of this rectangle.
 */
std::string Rectangle::name() const {
	return "Rectangle";
}

/*
 * @return	The number of sides this rectangle has.
 */
int Rectangle::numberOfSides() const {
	return 4;
}

/*
 * @return	The string representation of this rectangle.
 */
std::string Rectangle::toString() const {
	return "Rectangle | Width: " + std::to_string(m_width)
		+ ", Height: " + std::to_string(m_height);
}
