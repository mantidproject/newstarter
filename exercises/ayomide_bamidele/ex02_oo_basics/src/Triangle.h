#ifndef TRIANGLE_H
#define TRIANGLE_h
#include "Shape.h"
class Triangle : public Shape {
private:
  std::string type = "Triangle";
  int sides = 3;

public:
  double base, height;
  Triangle(double base, double height);
  double perimeter();
  double area();
  ~Triangle() = default;
};

#endif // !TRIANGLE_H
