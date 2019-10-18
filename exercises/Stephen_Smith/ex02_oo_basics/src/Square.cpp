// Square class implementation
#include "../include/Square.h"
#include <iostream>
const int Square::NUMSIDES = 4;
const std::string Square::SHAPENAME = std::string("Square");
/** Constructor
 * Initialises length, area and perimeter to zero
 */
Square::Square() 
{
	this->m_sideLength = 0.0;
	this->setArea(0.0);
	this->setPerimeter(0.0);
}
/** Constructor
 * Sets side length equal to input parameter, and calculates area and perimeter
 * @param sideLength : Input side length of square
 */
Square::Square(const double sideLength)
{
	// Set side length
	this->m_sideLength = sideLength;
	// Set area
	this->setArea(this->calculateArea());
	// Set perimeter
	this->setPerimeter(this->calculatePerimeter());
}
/** 
 * Prints current dimensions of the square
 */
void Square::printShapeDimensions() const
{
	std::cout << "Side length =" << this->m_sideLength;
}
/**
 * Returns the number of sides the shape has
 * @return : Number of sides
 */
int Square::getNumSides() const
{
	return this->NUMSIDES;
}
/**
 * Returns the type of shape
 * @return : Shape name
 */
std::string Square::getShapeName() const {
	return this->SHAPENAME;
}