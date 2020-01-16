/**
 * Skeleton main routine
 */

#include <iostream>
#include <memory>
#include <vector>

#include "shape.hpp"


using namespace std;

int main(int, char **) {
  vector<unique_ptr<Shape>> shapes;
  shapes.push_back(std::make_unique<Circle>(5));
  shapes.push_back(std::make_unique<Square>(5));
  shapes.push_back(std::make_unique<Rectangle>(1, 11));
  shapes.push_back(std::make_unique<Triangle>(5, 6));

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
