#ifndef TRIANGLE_H
#define TRIANGLE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Shape.h"

#include <math.h>

//===-- Triangle.h - Square definition -------*- C++ -*-======================//
//
//                          2-Dimmensional Shapes
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Triangle class, which is used to
/// initialize and access the data of triangle shapes. Inherits from the Shapes
/// class.
///
//===----------------------------------------------------------------------===//
class Triangle :
	public Shape
{
public:
	/// Constructs an isoceles triangle with a specified height
	/// and base length.
	Triangle(double height, double base);

	/// Returns the perimeter of the triangle.
	double perimeter() const override;

	/// Returns the area of the triangle.
	double area() const override;

	/// Returns the type of the triangle.
	ShapeType type() const override;

	/// Returns the name of this triangle.
	std::string name() const override;

	/// Returns the number of sides of the triangle.
	int numberOfSides() const override;

	/// Returns the string representation of the triangle.
	std::string toString() const override;
private:
	/// The height of the triangle.
	double m_height;

	/// The base length of the triangle.
	double m_base;
};

#endif /* TRIANGLE_H */