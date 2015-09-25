#ifndef SQUARE_H_
#define SQUARE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"

/**
	Square-type Shape implementation.

	Defined by the length of one side (since all sides are the same).
*/
class Square : public Shape
{
public:
	/// Constructor
	Square(double sidelength);
	
	/// Destructor
	virtual ~Square();

	/// Calculate perimeter of this Square
	virtual double calcPerimeter();

	/// Calculate area of this Square
	virtual double calcArea();

protected:
	/// Length of the sides of this Square
	double m_sideLength;
};

#endif // SQUARE_H_
