#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include <string>

class Square : public Shape {
private:
  const std::string type = "Square";
  const int sides = 4;

public:
  int getNoOfSides() const;
  std::string getType() const;
  double length;
  Square(double x);
  double area() const;
  double perimeter() const;
};
#endif // !SQUARE_H
