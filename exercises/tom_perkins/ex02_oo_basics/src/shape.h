#ifndef SHAPE_H_
#define SHAPE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include <string>

/**
 * \brief Shape is an abstract base class representing a shape.
 * 
 * It knows how many sides it has, its type and can
 * calculate its perimeter and area.
 */
class Shape
{
public:
	virtual double perimeter() const = 0; 
	virtual double area() const = 0;
	const int sides;
	const std::string type; 

protected:
	Shape(int sidesIn, std::string typeIn) : sides(sidesIn), type(typeIn) { };
};

#endif