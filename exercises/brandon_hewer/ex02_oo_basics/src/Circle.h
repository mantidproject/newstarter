#ifndef CIRCLE_H
#define CIRCLE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Shape.h"

//===-- Circle.h - Shape definition -------*- C++ -*-=========================//
//
//                          2-Dimmensional Shapes
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Circle class, which is used to
/// initialize and access the data of circle shapes. Inherits from the Shape
/// class.
///
//===----------------------------------------------------------------------===//
class Circle :
	public Shape
{
public:
	/// Constructs a circle with a specified radius.
	Circle(double radius);

	/// Destructor.
	~Circle();

	/// Returns the perimeter of the circle.
	double perimeter() const;

	/// Returns the area of the circle.
	double area() const;

	/// Returns the name of the circle.
	std::string name() const;

	/// Returns the number of sides of the circle.
	int numberOfSides() const;

	/// Returns the string representation of the circle.
	std::string toString() const;
private:
	/// The radius of the circle.
	double m_radius;
};

#endif /* CIRCLE_H */