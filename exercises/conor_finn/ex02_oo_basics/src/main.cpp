#include <iostream>
#include <vector>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "shapeSorter.h"
#include "square.h"
#include "triangle.h"

int main(int, char **) {
  std::vector<Shape *> shapes;

  // Make some shapes.
  Rectangle *r1 = new Rectangle(5, 10);
  Rectangle *r2 = new Rectangle(50, 10);
  Triangle *t1 = new Triangle(10, 23);
  Triangle *t2 = new Triangle(2, 60);
  Square *s1 = new Square(67);
  Circle *c1 = new Circle(42);

  // Add to vector.
  shapes.push_back(r1);
  shapes.push_back(r2);
  shapes.push_back(t1);
  shapes.push_back(t2);
  shapes.push_back(s1);
  shapes.push_back(c1);

  ShapeSorter sorter;

  // Printing squares.
  sorter.printMatchingName(shapes, "Square");
  // Printing rectangles.
  sorter.printMatchingName(shapes, "Triangle");

  std::cout << "Done!";
}