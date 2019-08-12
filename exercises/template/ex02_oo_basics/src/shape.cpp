#include "shape.hpp"

#include <algorithm>
#include <iostream>

ostream &operator<<(ostream &os, const unique_ptr<Shape> &shape) {
  // Print the important parts of a shape
  os << "A " << shape->type();
  os << " with " << shape->sides() << " sides";
  os << ", a permieter of " << shape->perimeter();
  os << ", and and area of " << shape->area();
  return os;
};

int Circle::sides() const { return 1; }
double Circle::perimeter() const { return 2 * M_PI * radius; }
double Circle::area() const { return M_PI * radius * radius; }
string Circle::type() const { return "circle"; }

int Square::sides() const { return 4; }
double Square::perimeter() const { return 4 * side; }
double Square::area() const { return side * side; }
string Square::type() const { return "square"; }

int Rectangle::sides() const { return 4; }
double Rectangle::perimeter() const { return 2 * (width + height); }
double Rectangle::area() const { return width * height; }
string Rectangle::type() const { return "rectangle"; }

int Triangle::sides() const { return 3; }
double Triangle::perimeter() const {
  return base + 2 * sqrt(height * height + base * base / 4);
}
double Triangle::area() const { return 0.5 * base * height; }
string Triangle::type() const { return "triangle"; }


void ShapeSorter::print() const {
  // print all shapes
  for (auto &shape : contents) {
    cout << shape << endl;
  }
}
void ShapeSorter::sides(const int side_count) const {
  // print shapes with given number of sides
  for_each(contents.begin(), contents.end(),
	   [side_count](const unique_ptr<Shape> &value) {
	     if (value->sides() == side_count)
	       cout << value << endl;
	   });
}
void ShapeSorter::typed(const string &type) const {
  // print shapes of a given type
  for_each(contents.begin(), contents.end(), [type](const unique_ptr<Shape> &value) {
					       if (value->type() == type)
						 cout << value << endl;
					     });
}

void ShapeSorter::area_sort() {
  // Sort contents by area and print
  sort(contents.begin(), contents.end(),
       [](unique_ptr<Shape> &a, unique_ptr<Shape> &b) {
	 return a->area() > b->area();
       });
  print();
}

void ShapeSorter::perimeter_sort() {
  // Sort contents by perimeter and print
  sort(contents.begin(), contents.end(),
       [](unique_ptr<Shape> &a, unique_ptr<Shape> &b) {
	 return a->perimeter() > b->perimeter();
       });
  print();
}
