#ifndef TRIANGLE_H_
#define TRIANGLE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"

/**
 * \brief Triangle represents an isoceles triangle
 */
class Triangle : Shape
{
public:
	Triangle(double heightIn, double baseIn);
	double perimeter() const;
    double area() const;

private:
	double height; 
	double base;
};

#endif