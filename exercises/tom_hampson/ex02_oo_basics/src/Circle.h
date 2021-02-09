#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
  Circle(const double radius);

private:
  void calculateArea() override;
  void calculatePerimeter() override;

  double m_radius;
};
