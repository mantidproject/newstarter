#ifndef CIRCLE_H_
#define CIRCLE_H_
#define _USE_MATH_DEFINES

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"
#include <cmath>

/**
 * \brief Circle represents a circle.
 */
class Circle : Shape
{
public:
	Circle(double radiusIn);
	double perimeter() const;
    double area() const;

private:
	double radius; 
};

#endif