//Triangle class implementation
#include "../include/Triangle.h"
#include <iostream>

const int Triangle::NUMSIDES = 3;
const std::string Triangle::SHAPENAME = std::string("Triangle");

/** Constructor
 * Initialises base, height, area, and perimeter to zero
 */
Triangle::Triangle()
{
	this->m_base = 0.0;
	this->m_height = 0.0;
	this->setArea(0.0);
	this->setPerimeter(0.0);
}
/** Constructor
 * Sets side lengths equal to input parameters, and calculates area and perimeter
 * @param base : Input base of triangle
 * @param height : Input height of triangle
 */
Triangle::Triangle(const double base, const double height)
{
	// Set base and height
	this->m_base = base;
	this->m_height = height;
	// Set area
	this->setArea(this->calculateArea());
	// Set perimeter
	this->setPerimeter(this->calculatePerimeter());
}
/**
 * Prints current dimensions of the triangle
 */
void Triangle::printShapeDimensions() const
{
	std::cout << "Base=" << this->m_base << "   Height=" << this->m_height;
}
/**
 * Returns the number of sides the shape has
 * @return : Number of sides
 */
int Triangle::getNumSides() const
{
	return this->NUMSIDES;
}
/**
 * Returns the type of shape
 * @return : Shape name
 */
std::string Triangle::getShapeName() const
{
	return this->SHAPENAME;
}
