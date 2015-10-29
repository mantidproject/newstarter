#ifndef RECTANGLE_H_
#define RECTANGLE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "shape.h"

/**
 * \brief Rectangle represents a rectangle
 */
class Rectangle : public Shape
{
public:
	Rectangle(double xIn, double yIn);
	Rectangle(double xIn, double yIn, std::string typeIn);
	virtual double perimeter() const;
    virtual double area() const;

private:
	double x; 
	double y;
};

#endif