// Circle class implementation
#include <iostream>
#include "../include/Circle.h"

const int Circle::NUMSIDES = 1;
const std::string Circle::SHAPENAME = std::string("Circle");
/** Constructor
 * Initialises radius, area and perimeter to zero
 */
Circle::Circle()
{
	this->m_radius = 0.0;
	this->setArea(0.0);
	this->setPerimeter(0.0);
}
/** Constructor
 * Sets radius to input parameter, and calculates area and perimeter
 * @param radius : Radius of circle
 */
Circle::Circle(const double radius)
{
	// Set radius
	this->m_radius = radius;
	// Set area
	this->setArea(this->calculateArea());
	// Set perimeter
	this->setPerimeter(this->calculatePerimeter());
}
/**
 * Prints current dimensions of the circle
 */
void Circle::printShapeDimensions() const
{
	std::cout << "Radius=" << this->m_radius;
}
/**
 * Returns the number of sides the shape has
 * @return : Number of sides
 */
int Circle::getNumSides() const
{
	return this->NUMSIDES;
}
/**
 * Returns the type of shape
 * @return : Shape name
 */
std::string Circle::getShapeName() const {
	return this->SHAPENAME;
}