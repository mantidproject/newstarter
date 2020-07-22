#pragma once

#include "Shape.h"

/*
 * Stores data for a square shape
 * Inherits from class Shape
 * lengthSides : Stores the length of each side of the square
 */
class Square : public Shape
{
public:
  /// Constructor of triangle
  Square(float _lengthSides);

  /// implementation of area and perimeter for a square (virtual in Shape class)
  float area();
  float perimeter();

private:
  float lengthSides;
};