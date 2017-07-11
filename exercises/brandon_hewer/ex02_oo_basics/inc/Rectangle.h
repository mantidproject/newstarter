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

	/// Returns the perimeter of the rectangle.
	double perimeter() const override;

	/// Returns the area of the rectangle.
	double area() const override;

	/// Returns the type of the rectangle.
	ShapeType type() const override;

	/// Returns the name of this rectangle.
	std::string name() const override;

	/// Returns the number of sides of the rectangle.
	int numberOfSides() const override;

	/// Returns a string representation of the rectangle.
	std::string toString() const override;
private:
	/// The width of the rectangle.
	double m_width;

	/// The height of the rectangle.
	double m_height;
};

#endif /* RECTANGLE_H */