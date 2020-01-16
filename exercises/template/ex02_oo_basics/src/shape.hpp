#ifndef SHAPE_HPP

#define SHAPE_HPP

#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

class Shape {
public:
  virtual unsigned int sides() const = 0;
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual string type() const = 0;
};

ostream &operator<<(ostream &os, const Shape *shape);

class Circle : public Shape {
private:
  double m_radius;

public:
  explicit Circle(double r) : m_radius(r) {}
  unsigned int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class Square : public Shape {
private:
  double m_side;

public:
  explicit Square(double s) : m_side(s) {}
  unsigned int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class Rectangle : public Shape {
private:
  double m_width;
  double m_height;

public:
  explicit Rectangle(double w, double h) : m_width(w), m_height(h) {}
  unsigned int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class Triangle : public Shape {
private:
  double m_base;
  double m_height;

public:
  explicit Triangle(double b, double h) : m_base(b), m_height(h) {}
  unsigned int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class ShapeSorter {
private:
  vector<unique_ptr<Shape>> m_shapes;

public:
  explicit ShapeSorter(vector<unique_ptr<Shape>> &c) : m_shapes(move(c)){};
  void print() const;
  void sides(const int side_count) const;
  void typed(const string &type) const;
  void area_sort();
  void perimeter_sort();
};

#endif
