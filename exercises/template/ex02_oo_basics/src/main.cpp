/**
 * Skeleton main routine
 */

#include <iostream>
#include <math.h>
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

int main(int, char **)
{
  //FIXME: This currently leaks memory
  vector<Shape*> shapes = {new Circle(5), new Square(5), new Rectangle(3, 7)};
  for (auto shape : shapes) {
    cout << shape->type() << endl;
    cout << shape->sides() << endl;
    cout << shape->perimeter() << endl;
    cout << shape->area() << endl;
  }
}
