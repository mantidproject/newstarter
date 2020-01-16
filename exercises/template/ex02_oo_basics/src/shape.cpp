#include "shape.hpp"

#include <algorithm>
#include <iostream>

const int circleFaces = 1;
const int triangleFaces = 3;
const int quadralateralFaces = 4;

ostream &operator<<(ostream &os, const unique_ptr<Shape> &shape) {
  // Print the important parts of a shape
  os << "A " << shape->type();
  os << " with " << shape->sides() << " sides";
  os << ", a permieter of " << shape->perimeter();
  os << ", and and area of " << shape->area();
  return os;
};

unsigned int Circle::sides() const { return circleFaces; }
double Circle::perimeter() const { return 2 * M_PI * m_radius; }
double Circle::area() const { return M_PI * m_radius * m_radius; }
string Circle::type() const { return "circle"; }

unsigned int Square::sides() const { return quadralateralFaces; }
double Square::perimeter() const { return 4 * m_side; }
double Square::area() const { return m_side * m_side; }
string Square::type() const { return "square"; }

unsigned int Rectangle::sides() const { return quadralateralFaces; }
double Rectangle::perimeter() const { return 2 * (m_width + m_height); }
double Rectangle::area() const { return m_width * m_height; }
string Rectangle::type() const { return "rectangle"; }

unsigned int Triangle::sides() const { return triangleFaces; }
double Triangle::perimeter() const {
  return m_base + 2 * sqrt(m_height * m_height + m_base * m_base / 4);
}
double Triangle::area() const { return 0.5 * m_base * m_height; }
string Triangle::type() const { return "triangle"; }


void ShapeSorter::print() const {
  // print all shapes
  for (auto &shape : m_shapes) {
    cout << shape << endl;
  }
}
void ShapeSorter::sides(const int side_count) const {
  // print shapes with given number of sides
  for_each(m_shapes.begin(), m_shapes.end(),
	   [side_count](const unique_ptr<Shape> &value) {
	     if (value->sides() == side_count)
	       cout << value << endl;
	   });
}
void ShapeSorter::typed(const string &type) const {
  // print shapes of a given type
  for_each(m_shapes.begin(), m_shapes.end(),
	   [&type](const unique_ptr<Shape> &value) {
	     if (value->type() == type)
	       cout << value << endl;
	   });
}

void ShapeSorter::area_sort() {
  // Sort contents by area and print
  sort(m_shapes.begin(), m_shapes.end(),
       [](unique_ptr<Shape> &a, unique_ptr<Shape> &b) {
	 return a->area() > b->area();
       });
  print();
}

void ShapeSorter::perimeter_sort() {
  // Sort contents by perimeter and print
  sort(m_shapes.begin(), m_shapes.end(),
       [](unique_ptr<Shape> &a, unique_ptr<Shape> &b) {
	 return a->perimeter() > b->perimeter();
       });
  print();
}
