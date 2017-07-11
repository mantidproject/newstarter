#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {

private:
  int m_radius;

public:
  Circle(int radius);
  int getNumSides() const override;
  double getArea() const override;
  double getPerimeter() const override;
  ShapeType getType() const override;
  std::string toString() const override;
};

#endif
