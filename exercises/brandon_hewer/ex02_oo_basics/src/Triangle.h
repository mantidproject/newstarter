#ifndef TRIANGLE_H
#define TRIANGLE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Shape.h"

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

	/// Destructor.
	~Triangle();

	/// Returns the perimeter of the triangle.
	double perimeter() const;

	/// Returns the area of the triangle.
	double area() const;

	/// Returns the name of the triangle.
	std::string name() const;

	/// Returns the number of sides of the triangle.
	int numberOfSides() const;

	/// Returns the string representation of the triangle.
	std::string toString() const;
private:
	/// The height of the triangle.
	double m_height;

	/// The base length of the triangle.
	double m_base;
};

#endif /* TRIANGLE_H */