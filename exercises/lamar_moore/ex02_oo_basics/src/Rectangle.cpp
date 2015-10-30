#include "Rectangle.h"


namespace Shapes
{
	/** Constructor for Rectangle object
	@param length Length of the rectangle
	@param width Width of the rectangle
	*/
	Rectangle::Rectangle(double length, double width)
	{
		this->width = width;
		this->length = length;
		this->type = ShapeType::RECTANGLE;
		this->numSides = 4;
	}

	Rectangle::~Rectangle()
	{
	}

	/** Calculate and return the area of the rectangle.
	*/
	double Rectangle::calculateArea()
	{
		return width * length;
	}

	/** Calculate and return the perimeter of the rectangle

	*/
	double Rectangle::calculatePerimeter()
	{
		return ( (2 * width) + (2 * length) );
	}

};