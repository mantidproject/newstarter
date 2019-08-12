#ifndef SHAPE_HPP

#define SHAPE_HPP

#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

class Shape {
public:
  virtual int sides() const = 0;
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual string type() const = 0;
};

ostream &operator<<(ostream &os, const Shape *shape);

class Circle : public Shape {
private:
  double radius;

public:
  explicit Circle(double r) : radius(r) {}
  int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class Square : public Shape {
private:
  double side;

public:
  explicit Square(double s) : side(s) {}
  int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class Rectangle : public Shape {
private:
  double width;
  double height;

public:
  explicit Rectangle(double w, double h) : width(w), height(h) {}
  int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class Triangle : public Shape {
private:
  double base;
  double height;

public:
  explicit Triangle(double b, double h) :base(b), height(h) {}
  int sides() const override;
  double perimeter() const override;
  double area() const override;
  string type() const override;
};

class ShapeSorter {
private:
  vector<unique_ptr<Shape>> contents;

public:
  explicit ShapeSorter(vector<unique_ptr<Shape>> &c) : contents(move(c)){};
  void print() const;
  void sides(const int side_count) const;
  void typed(const string &type) const;
  void area_sort();
  void perimeter_sort();
};

#endif
