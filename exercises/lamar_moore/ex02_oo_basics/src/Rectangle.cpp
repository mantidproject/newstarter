#include "Rectangle.h"


namespace Shapes
{
	/** Constructor for Rectangle object
	@param length Length of the rectangle
	@param width Width of the rectangle
	*/
	Rectangle::Rectangle(double length, double width): m_length(length), m_width(width)
	{
	}

	Rectangle::~Rectangle()
	{
	}

	/** Calculate and return the area of the rectangle.
	*/
	const double Rectangle::calculateArea()
	{
		return m_width * m_length;
	}

	/** Calculate and return the perimeter of the rectangle

	*/
	const double Rectangle::calculatePerimeter()
	{
		return ( (2 * m_width) + (2 * m_length) );
	}

	const string Rectangle::getType()
	{
		return "Rectangle";
	}

	const int Rectangle::getNumSides()
	{
		return 4;
	}

};