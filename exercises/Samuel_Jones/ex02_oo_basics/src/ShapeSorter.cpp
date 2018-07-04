#include "ShapeSorter.h"
#include "make_unique.h"
#include <algorithm>

ShapeSorter::ShapeSorter() {}
void ShapeSorter::printOutShapesOfType(
    std::vector<std::unique_ptr<Shape>> const &shapes, std::string type) {
  // For each object in shapes if the shape has type equal to required type
  // print shape
  for (auto const &shape : shapes) {
    if (shape->getType() == type) {
      printShape(*shape);
    }
  }
}

void ShapeSorter::printOutShapesOfSides(
    std::vector<std::unique_ptr<Shape>> const &shapes, int sides) {
  for (auto const &shape : shapes) {
    // If needs 4 sides and the shape has a type that has 4 sides as we don't
    // store sides, print shape
    if (sides == 4 &&
        (shape->getType() == "Square" || shape->getType() == "Rectangle")) {
      printShape(*shape);
      // Else if needs 3 and has 3 sides type, print shape
    } else if (sides == 3 && shape->getType() == "Triangle") {
      printShape(*shape);
      // Else if needs 1 and has 1 sides type, print shape
    } else if (sides == 1 && shape->getType() == "Circle") {
      printShape(*shape);
    }
  }
}

void ShapeSorter::printOutShapesInOrderOfArea(
    std::vector<std::unique_ptr<Shape>> &shapes) {
  // Order shapes in descending order according to area inside the vector using
  // a comparator
  sort(shapes.begin(), shapes.end(),
       [](const std::unique_ptr<Shape> &a, const std::unique_ptr<Shape> &b)
           -> bool { return a->getArea() < b->getArea(); });
  // Then print the whole vector
  for (auto const &shape : shapes) {
    printShape(*shape);
  }
}
void ShapeSorter::printOutShapesInOrderOfPerimeter(
    std::vector<std::unique_ptr<Shape>> &shapes) {
  // Order shapes in descending order according to Perimeter inside the vector
  // using a comparator
  sort(shapes.begin(), shapes.end(),
       [](const std::unique_ptr<Shape> &a, const std::unique_ptr<Shape> &b)
           -> bool { return a->getPerimeter() < b->getPerimeter(); });
  // Then print the whole vector
  for (auto const &shape : shapes) {
    printShape(*shape);
  }
}

// Print out the shape in a given format, easy for reuse throughout object but
// not public so private
void ShapeSorter::printShape(Shape const &shape) {
  std::cout << "Type is: " << shape.getType() << " Area is: " << shape.getArea()
            << " Perimeter is: " << shape.getPerimeter() << std::endl;
}