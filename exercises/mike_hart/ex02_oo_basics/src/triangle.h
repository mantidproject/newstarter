#ifndef TRIANGLE_H_
#define TRIANGLE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"

/**
	Triangle-type Shape implementation.

	Defined by a height and a base length. Assumed to be isoceles.
*/
class Triangle : public Shape
{
public:
	/// Constructor
	Triangle(double height, double base);
	
	/// Destructor
	virtual ~Triangle();

	/// Calculate perimeter of this Triangle
	virtual double calcPerimeter();

	/// Calculate area of this Triangle
	virtual double calcArea();

protected:
	/// Height of this Triangle
	double m_height;

	/// Base of this Triangle
	double m_base;
};

#endif // TRIANGLE_H_
