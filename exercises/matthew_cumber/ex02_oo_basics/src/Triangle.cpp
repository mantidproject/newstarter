#include <iostream>
#include <string>
#include <cmath>
#include "Triangle.h"

/** Creates an instance of a Triangle 
 * @param _height Value of the height of the triangle
 * @param _base Value of the base of the triangle 
 */
Triangle::Triangle(float _height, float _base)
{
  height = _height;
  base = _base;
  type = "Triangle";
  numSides = 3;
}

/** Calculates the area of a triangle
 * @return Value of area
 */
float Triangle::area()
{
  return (height*base)/2.0;
}

/** Calculates the perimeter of a triangle
 * @return Value of perimeter
 */
float Triangle::perimeter()
{
  float baseSquaredOverFour = pow(base,2)/4.0;
  float root = sqrt(pow(height,2) + baseSquaredOverFour);
  return base + 2.0*root;
}