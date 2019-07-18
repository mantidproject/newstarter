#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "shape.h"

class Circle : public Shape {
private:
  const int radius;

public:
  Circle(int radius);
  double perimiter() const override;
  double area() const override;
};

#endif