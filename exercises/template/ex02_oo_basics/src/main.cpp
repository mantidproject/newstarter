/**
 * Skeleton main routine
 */

#include <iostream>
#include <math.h>

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

int main(int, char **)
{
  Circle trial(5);
  cout << "Hello, World!" << endl;
  cout << trial.sides() << endl;
  cout << trial.perimeter() << endl;
  cout << trial.area() << endl;
}
