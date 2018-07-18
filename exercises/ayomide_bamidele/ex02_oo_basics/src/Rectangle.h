#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <string>

class Rectangle : public Shape {
private:
  std::string type = "Rectangle";
  int sides = 4;

public:
  double length, breadth;

  Rectangle(double x, double y);
  double area();
  double perimeter();

  ~Rectangle() = default;
};

#endif // !RECTANGLE_H
