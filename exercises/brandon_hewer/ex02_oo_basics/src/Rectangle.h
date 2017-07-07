#ifndef RECTANGLE_H
#define RECTANGLE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Shape.h"

//===-- Rectangle.h - Rectangle definition -------*- C++ -*-==================//
//
//                          2-Dimmensional Shapes
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Rectangle class, which is used
/// to initialize and access the data of rectangle shapes. Inherits from the
/// Shape class.
///
//===----------------------------------------------------------------------===//
class Rectangle :
	public Shape
{
public:
	/// Constructs a rectangle with a specified width
	/// and height.
	Rectangle(double width, double height);

	/// Destructor.
	~Rectangle();

	/// Returns the perimeter of the rectangle.
	double perimeter() const;

	/// Returns the area of the rectangle.
	double area() const;

	/// Returns the name of the rectangle.
	virtual std::string name() const;

	/// Returns the number of sides of the rectangle.
	int numberOfSides() const;

	/// Returns a string representation of the rectangle.
	std::string toString() const;
private:
	/// The width of the rectangle.
	double m_width;

	/// The height of the rectangle.
	double m_height;
};

#endif /* RECTANGLE_H */