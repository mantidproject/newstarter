/**
 * Skeleton main routine
 */

#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

class Shape {
public:
  virtual int sides() = 0;
  virtual double perimeter() = 0;
  virtual double area() = 0;
  virtual string type() = 0;
};

class Circle : public Shape {
private:
  double radius;
public:
  explicit Circle(double r) {
    radius = r;
  }
  int sides() override {
    return 1;
  }
  double perimeter() override {
    return 2 * M_PI * radius;
  }
  double area() override {
    return M_PI * radius * radius;
  }
  string type() override {
    return "circle";
  }
};

class Square : public Shape {
private:
  double side;
public:
  explicit Square(double s) {
    side = s;
  }
  int sides() override {
    return 4;
  }
  double perimeter() override {
    return 4 * side;
  }
  double area() override {
    return side*side;
  }
  string type() override {
    return "square";
  }
};

class Rectangle : public Shape {
private:
  double width;
  double height;
public:
  explicit Rectangle(double w, double h) {
    width = w;
    height = h;
  }
  int sides() override {
    return 4;
  }
  double perimeter() override {
    return 2 * (width + height);
  }
  double area() override {
    return width*height;
  }
  string type() override {
    return "rectangle";
  }
};

class Triangle : public Shape {
private:
  double base;
  double height;
public:
  explicit Triangle(double b, double h) {
    base = b;
    height = h;
  }
  int sides() override {
    return 3;
  }
  double perimeter() override {
    return base + 2 * sqrt(height*height + base*base/4);
  }
  double area() override {
    return 0.5*base*height;
  }
  string type() override {
    return "triangle";
  }
};

class ShapeSorter {
private:
  vector<shared_ptr<Shape>> contents;
public:
  ShapeSorter(vector<shared_ptr<Shape>> &c) {
    contents = c;
  }
  void print() {
    for (auto &shape : contents) {
      cout << shape->type() << endl;
      cout << shape->sides() << endl;
      cout << shape->perimeter() << endl;
      cout << shape->area() << endl;
    }
  }
};

int main(int, char **)
{
  vector<shared_ptr<Shape>> shapes;
  shapes.push_back(shared_ptr<Shape>(new Circle(5)));
  shapes.push_back(shared_ptr<Shape>(new Square(5)));
  shapes.push_back(shared_ptr<Shape>(new Rectangle(3, 7)));
  shapes.push_back(shared_ptr<Shape>(new Triangle(5, 6)));

  ShapeSorter sorter(shapes);
  sorter.print();
}
