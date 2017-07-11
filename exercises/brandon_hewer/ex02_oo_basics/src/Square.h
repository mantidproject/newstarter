#ifndef SQUARE_H
#define SQUARE_H
//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include "Rectangle.h"

//===-- Square.h - Square definition -------*- C++ -*-=========================//
//
//                          2-Dimmensional Shapes
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Square class, which is used to
/// initialize and access the data of square shapes. Inherits from the
/// Rectangle class.
///
//===----------------------------------------------------------------------===//
class Square :
	public Rectangle
{
public:
	/// Constructs a square of a specified size.
	Square(double size);

	/// Returns the type of the square.
	ShapeType type() const override;

	/// Returns the name of this square.
	std::string name() const override;

	/// Returns the string representation of the square.
	std::string toString() const override;
private:
	/// The size of the square.
	double m_size;
};

#endif /* SQUARE_H */