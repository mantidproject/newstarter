#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
// Includes
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

// Class definition
class ShapeFactory {
public:
  ShapeFactory(); // Default constructor
  ~ShapeFactory();

  Circle *createCircle(const double &radius);
  Rectangle *createRectangle(const double &height, const double &width);
  Square *createSquare(const double &length);
  Triangle *createTriangle(const double &height, const double &base);

private:
};
#endif

// End of File