/**
 * Skeleton main routine
 */

#include <iostream>
#include <memory>
#include <vector>

#include "shape.hpp"


using namespace std;

int main(int, char **) {
  vector<shared_ptr<Shape>> shapes = {
  (shared_ptr<Shape>(new Circle(5))),
  (shared_ptr<Shape>(new Square(5))),
  (shared_ptr<Shape>(new Rectangle(1, 11))),
  (shared_ptr<Shape>(new Triangle(5, 6)))
  };

  ShapeSorter sorter(shapes);
  sorter.sides(4);
  cout << endl;
  sorter.typed("circle");
  cout << endl;
  sorter.area_sort();
  cout << endl;
  sorter.perimeter_sort();
  cout << endl;
}
