#ifndef RECTANGLE_H_
#define RECTANGLE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"

/**
	Rectangle-type Shape implementation.

	Defined by two side lengths (which may or may not be the same).
*/
class Rectangle : public Shape
{
public:
	/// Constructor
	Rectangle(double side1, double side2);
	
	/// Destructor
	virtual ~Rectangle();

	/// Calculate perimeter of this Rectangle
	virtual double calcPerimeter();

	/// Calculate area of this Rectangle
	virtual double calcArea();

protected:
	/// Length of first side of this Rectangle
	double m_sideLength1;

	/// Length of second side of this Rectangle
	double m_sideLength2;
};

#endif // RECTANGLE_H_
