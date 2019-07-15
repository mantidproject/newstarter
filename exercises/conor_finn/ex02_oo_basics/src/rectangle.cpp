#include "rectangle.h"

/**
 * @brief Construct a new Rectangle:: Rectangle object
 * 
 * @param s1 Width of rectangle. 
 * @param s2 Length of rectangle. 
 */
Rectangle::Rectangle(int s1, int s2): Shape(4, "Rectangle") {
  side1 = s1 ; side2 = s2;
}

/**
 * @brief Calcualte perimiter. 
 * 
 * @return double Perimiter result. 
 */
double Rectangle::perimiter() {
  return (side1 * 2) + (side2 * 2);
}

/**
 * @brief Calcualte area. 
 * 
 * @return double Area result. 
 */
double Rectangle::area() {
  return side1 * side2;
}