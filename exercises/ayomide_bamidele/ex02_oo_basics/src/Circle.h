#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>
class Circle : public Shape {
private:
  const std::string type = "Circle";
  const int sides = 1;

public:
  int getNoOfSides() const;
  std::string getType() const;
  double radius;
  Circle(double r);
  double area() const;
  double perimeter() const;
};
#endif // !CIRCLE_H
