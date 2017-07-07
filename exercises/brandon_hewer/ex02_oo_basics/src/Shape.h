#ifndef SHAPE_H
#define SHAPE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <string>
#include <sstream>

//===-- Shape.h - Shape definition -------*- C++ -*-==========================//
//
//                          2-Dimmensional Shapes
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Shape class, which is the base,
/// abstract class for all shapes.
///
//===----------------------------------------------------------------------===//
class Shape
{
public:
	/// Returns the perimeter of the shape.
	virtual double perimeter() const = 0;

	/// Returns the area of the shape.
	virtual double area() const = 0;

	/// Returns the name of the shape.
	virtual std::string name() const = 0;
	
	/// Returns the number of sides of the shape.
	virtual int numberOfSides() const = 0;

	/// Returns the string representation of the shape.
	virtual std::string toString() const = 0;
};

#endif /* SHAPE_H */