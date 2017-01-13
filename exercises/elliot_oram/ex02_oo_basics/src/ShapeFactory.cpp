// Includes
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeFactory.h"
#include "Square.h"
#include "Triangle.h"

// Constructors
ShapeFactory::ShapeFactory() {}
ShapeFactory::~ShapeFactory() {}

// Member Functions

/**
 *Creates a new Shape of type Square
 *@param length The length of one side of the square
 *@return A pointer to the new object of type Square
 */
Square *ShapeFactory::createSquare(const double &length) {
  return new Square(length, length);
}

/**
 *Creates a new Shape of type Circle
 *@param radius The radius of the circle
 *@return A pointer to the new object of type Circle
 */
Circle *ShapeFactory::createCircle(const double &radius) {
  return new Circle(radius);
}

/**
 *Creates a new Shape of type Rectangle
 *@param height The height of the rectangle
 *@param width The width of the rectangle
 *@return A pointer to the new object of type Rectangle
 */
Rectangle *ShapeFactory::createRectangle(const double &height,
                                         const double &width) {
  return new Rectangle(height, width);
}

/**
 *Creates a new Shape of type Triangle
 *@param height The height of the triangle
 *@param base The width of the base of triangle
 *@return A pointer to the new object of type Triangle
 */
Triangle *ShapeFactory::createTriangle(const double &height,
                                       const double &base) {
  return new Triangle(height, base);
}

// End of File