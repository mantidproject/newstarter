#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <string>

class Rectangle : public Shape {
private:
  const std::string type = "Rectangle";
  const int sides = 4;

public:
  int getNoOfSides() const;
  double length, breadth;
  std::string getType() const;
  Rectangle(double x, double y);
  double area() const;
  double perimeter() const;
};

#endif // !RECTANGLE_H
