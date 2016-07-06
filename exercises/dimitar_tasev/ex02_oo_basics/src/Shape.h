#ifndef SHAPE_H_
#define SHAPE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <string>

/*
	Abstract definition for base class Shape
*/
class Shape {
public:
	virtual ~Shape(){};

	/// Returns the side of the Square
	virtual int getSides() const = 0;

	/// Returns the type
	virtual std::string getType() const = 0;

	/// Returns the volume (area) 
	virtual float getVolume() const = 0;

	/// Returns the perimeter
	virtual float getPerimeter() const = 0;

};

#endif /* SHAPE_H_ */
