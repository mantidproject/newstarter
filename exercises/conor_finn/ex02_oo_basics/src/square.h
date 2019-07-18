#ifndef SQUARE_H_
#define SQUARE_H_

#include "shape.h"

class Square : public Shape {
private:
  const int side1;

public:
  Square(int sideLen);
  double perimiter() const override;
  double area() const override;
};

#endif