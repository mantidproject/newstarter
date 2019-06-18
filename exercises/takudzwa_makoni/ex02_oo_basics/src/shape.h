#ifndef SHAPE_H
#define SHAPE_H

#include <string>

struct Shape {

	virtual unsigned int numOfSides() const = 0; 
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual std::string shapeType() const = 0;

};



#endif