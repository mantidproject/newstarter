#ifndef CIRCLE_H_
#define CIRCLE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"

/**
	Circle-type Shape implementation.

	Defined by a radius. 
*/
class Circle : public Shape
{
public:
	/// Constructor
	Circle(double radius);
	
	/// Destructor
	virtual ~Circle();

	/// Calculate perimeter of this Circle
	virtual double calcPerimeter();

	/// Calculate area of this Circle
	virtual double calcArea();

protected:
	/// Radius of this Circle
	double m_radius;
};

#endif // CIRCLE_H_
