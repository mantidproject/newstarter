#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <string>

class Rectangle : public Shape {
private:
  std::string type = "Rectangle";
  int sides = 4;

public:
  int getNoOfSides() const;
  double length, breadth;
  std::string getType() const;
  Rectangle(double x, double y);
  double area() const;
  double perimeter() const;

  ~Rectangle() = default;
};

#endif // !RECTANGLE_H
