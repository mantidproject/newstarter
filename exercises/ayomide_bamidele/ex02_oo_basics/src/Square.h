#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include <string>

class Square : public Shape {
private:
  std::string type = "Square";
  int sides = 4;

public:
  double length;
  Square(double x);
  double area();
  double perimeter();

  ~Square() = default;
};
#endif // !SQUARE_H
