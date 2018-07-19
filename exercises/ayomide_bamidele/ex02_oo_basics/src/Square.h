#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include <string>

class Square : public Shape {
private:
  std::string type = "Square";
  int sides = 4;
  static int id;

public:
  int getNoOfSides() const;
  std::string getType() const;
  double length;
  Square(double x);
  double area() const;
  double perimeter() const;

  ~Square() = default;
};
#endif // !SQUARE_H
