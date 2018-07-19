#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::cout << "Create 4 Shapes" << std::endl;
  std::cout << "Circle: radius = 1" << std::endl;
  std::cout << "Triangle: base = 1, height = 1" << std::endl;
  std::cout << "Square: length = 1" << std::endl;
  std::cout << "Rectangle: length = 1, breadth = 1\n" << std::endl;

  auto circle = Circle(1.0);
  auto triangle = Triangle(1, 1);
  auto square = Square(1);
  auto rectangle = Rectangle(1, 1);
  auto sorter = ShapeSorter();

  std::vector<Shape *> vecShapes{&circle, &triangle, &square, &rectangle};

  std::cout << "***Printing by Perimeter***" << std::endl;
  sorter.printByPerimeter(vecShapes);

  std::cout << "***Printing by side***" << std::endl;
  sorter.printBySide(vecShapes, 4);

  std::cout << "***Printing by type***" << std::endl;
  sorter.printByType(vecShapes, "Square");

  std::cout << "***Printing by area***" << std::endl;
  sorter.printByVolume(vecShapes);

  return 0;
}
