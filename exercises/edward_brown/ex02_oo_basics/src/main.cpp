#include "Circle.h"
#include "Rectangle.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"
#include <iostream>
#include <memory>
#ifndef _MSC_VER
#include "StdMakeUnique.h" // This provides std::make_unique - Would use boost equivalent or similar if available.
#endif

using ShapeVector = typename ShapeSorter::ShapeVector;

ShapeVector makeShapeList() {
  ShapeVector shapes;
  shapes.emplace_back(std::make_unique<Circle>(10.0));
  shapes.emplace_back(std::make_unique<Triangle>(10.0, 5.0));
  shapes.emplace_back(std::make_unique<Rectangle>(4.0, 8.0));
  shapes.emplace_back(std::make_unique<Square>(3.0));
  return std::move(shapes);
}

int main(int, char **) {
  auto shapeList = makeShapeList();
  auto shapeSorter = ShapeSorter(std::move(shapeList), std::cout);
  shapeSorter.printByAreaDescending();
}
