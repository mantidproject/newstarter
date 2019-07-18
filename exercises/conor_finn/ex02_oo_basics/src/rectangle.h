#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

class Rectangle : public Shape {
private:
  const int side1;
  const int side2;

public:
  Rectangle(int s1, int s2);
  double perimiter() const override;
  double area() const override;
};

#endif