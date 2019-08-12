#ifndef SHAPE_HPP

#define SHAPE_HPP

#include <algorithm>
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
  vector<shared_ptr<Shape>> contents;

public:
  explicit ShapeSorter(vector<shared_ptr<Shape>> &c) : contents(c){};
  void print() {
    // print all shapes
    for (auto &shape : contents) {
      cout << shape << endl;
    }
  }
  void sides(const int side_count) {
    // print shapes with given number of sides
    for_each(contents.begin(), contents.end(),
	     [side_count](shared_ptr<Shape> value) {
	       if (value->sides() == side_count)
		 cout << value << endl;
	     });
  }
  void typed(const string &type) {
    // print shapes of a given type
    for_each(contents.begin(), contents.end(), [type](shared_ptr<Shape> value) {
      if (value->type() == type)
	cout << value << endl;
    });
  }

  void area_sort() {
    // Sort contents by area and print
    sort(contents.begin(), contents.end(),
	 [](shared_ptr<Shape> a, shared_ptr<Shape> b) {
	   return a->area() > b->area();
	 });
    print();
  }

  void perimeter_sort() {
    // Sort contents by perimeter and print
    sort(contents.begin(), contents.end(),
	 [](shared_ptr<Shape> a, shared_ptr<Shape> b) {
	   return a->perimeter() > b->perimeter();
	 });
    print();
  }
};

#endif
