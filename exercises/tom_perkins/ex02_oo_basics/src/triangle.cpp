#include "triangle.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Construct a new Triangle with given base, height
 * \param heightIn Height of isosceles triangle
 * \param baseIn Base of isosceles triangle
 * \param nameIn Name to give the shape
 */
Triangle::Triangle(double heightIn, double baseIn, std::string nameIn) : Shape(3, "triangle", nameIn)
{
	height = heightIn;
	base = baseIn;
}

/**
 * \brief Calculates the perimeter of this triangle.
 *
 * Assumes this triangle is isosceles:
 * p = b + 2\sqrt{h^2 + (b^2/4)}
 *
 * \returns Perimeter of the triangle.
 */
double Triangle::perimeter() const
{
	return base + 2.0 * sqrt(height * height + 0.25 * base * base);
}

/**
 * \brief Calculates the area of this triangle.
 * \returns Area of the triangle.
 */
double Triangle::area() const
{
	return 0.5 * base * height;
}