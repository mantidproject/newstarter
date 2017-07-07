#include "shapeSorter.h"
#include "shapes.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {

  std::vector<Shape *> shapes;
  Triangle t(1, 2);
  Rectangle r(1, 2);
  Circle c(2);
  Square s(2);
  shapes.push_back(&t);
  shapes.push_back(&r);
  shapes.push_back(&c);
  shapes.push_back(&s);

  ShapeSorter ss(shapes);
  ss.shapesInPerimeterOrder();
}
