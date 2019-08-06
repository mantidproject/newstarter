#include "main.h"

int main() {
  std::vector<Shape> vecShape;

  // create shapes
  Shape c1 = new Circle(4);
  Shape c2 = new Circle(4);
  Shape c3 = new Circle(10);
  Shape t1 = new Triangle(4, 7);
  Shape t2 = new Triangle(0, 2);
  Shape r1 = new Rectangle(5, 3);
  Shape r2 = new Rectangle(4);

  // populate vector
  vecShape.push_back(c1);
  vecShape.push_back(c2);
  vecShape.push_back(c3);
  vecShape.push_back(t1);
  vecShape.push_back(t2);
  vecShape.push_back(r1);
  vecShape.push_back(r2);

  ShapeSorter shapeSort = ShapeSorter(vecShape);
  shapeSort.printType("Circle");
  shapeSort.printType("Triangle");
  shapeSort.printType("Rectangle");
  shapeSort.printSides(1);
  shapeSort.printSides(3);
  shapeSort.printSides(4);
  shapeSort.printAreaDescending();
  shapeSort.printPerimeterDescending();
}