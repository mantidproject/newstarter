#ifndef TRIANGLE_H
#define TRIANGLE_h
#include "Shape.h"
class Triangle : public Shape {
private:
  std::string type = "Triangle";
  int sides = 3;

public:
  int getNoOfSides() const;
  std::string getType() const;
  double base, height;
  Triangle(double base, double height);
  double perimeter() const;
  double area() const;
  ~Triangle() = default;
};

#endif // !TRIANGLE_H
