#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>
class Circle : public Shape {
private:
  std::string type = "Circle";
  int sides = 1;

public:
  double radius;
  Circle(double r);
  double area();
  double perimeter();
  ~Circle() = default;
};
#endif // !CIRCLE_H
