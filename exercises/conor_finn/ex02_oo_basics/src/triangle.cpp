#include<cmath>
#include "triangle.h"

/**
 * @brief Construct a new Triangle:: Triangle object
 * 
 * @param h Height of triangle.
 * @param b Base of triangle. 
 */
Triangle::Triangle(int h, int b): Shape(3, "Triangle") {
  height = h;
  base = b;
}

/**
 * @brief Calculate perimiter.
 * 
 * @return double Perimiter of triangle. 
 */
double Triangle::perimiter() {
  return (base + (2*(sqrt(pow(height,2)+(pow(base,2)/4)))));
}

/**
 * @brief Calculate area. 
 * 
 * @return double Area of triangle. 
 */
double Triangle::area() {
  return (base*height)/2;
}