#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "shape.h"

class Circle : public Shape {
private:
  const int m_radius;

public:
  Circle(int radius);
  double perimiter() const override;
  double area() const override;
};

#endif // CIRCLE_H_