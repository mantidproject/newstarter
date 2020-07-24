#pragma once

#include <math.h>
#include "shape.h"

class Circle: public Shape {
  public:
    Circle(double r);

    const double getArea() override;

    const double getPerimeter() override;

  private:
    double m_radius;
};