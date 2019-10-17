// Rectangle class implementation
#include "../include/Rectangle.h"
#include <iostream>
const int Rectangle::NUMSIDES = 4;
const std::string Rectangle::SHAPENAME = std::string("Rectangle");

/** Constructor
 * Initialises width, depth, area, and perimeter to zero
 */ 
Rectangle::Rectangle()
{
	this->m_depth = 0.0;
	this->m_width = 0.0;
	this->setArea(0.0);
	this->setPerimeter(0.0);
}
/** Constructor
 * Sets side lengths equal to input parameters, and calculates area and perimeter
 * @param width : Input width of rectangle
 * @param depth : Input depth of rectangle
 */
Rectangle::Rectangle(const double width, const double depth)
{
	// set width and depth
	this->m_depth = depth;
	this->m_width = width;
	// Set area
	this->setArea(this->calculateArea());
	// Set perimeter
	this->setPerimeter(this->calculatePerimeter());
}
/**
 * Prints current dimensions of the rectangle
 */
void Rectangle::printShapeDimensions() const
{
	std::cout << "Width=" << this->m_width << "   Depth=" << this->m_depth;
}
/**
 * Returns the number of sides the shape has
 * @return : Number of sides
 */
int Rectangle::getNumSides() const
{
	return this->NUMSIDES;

}
/**
 * Returns the type of shape
 * @return : Shape name
 */
std::string Rectangle::getShapeName() const {
	return this->SHAPENAME;
}

