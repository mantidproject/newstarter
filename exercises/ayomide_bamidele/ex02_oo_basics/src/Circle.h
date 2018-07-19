#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>
class Circle : public Shape {
private:
  std::string type = "Circle";
  int sides = 1;

public:
  int getNoOfSides() const;
  std::string getType() const;
  double radius;
  Circle(double r);
  double area() const;
  double perimeter() const;
  ~Circle() = default;
};
#endif // !CIRCLE_H
