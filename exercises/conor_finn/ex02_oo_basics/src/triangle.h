#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"

class Triangle : public Shape {
private:
  const int m_height;
  const int m_base;

public:
  Triangle(int height, int base);
  double perimiter() const override;
  double area() const override;
};

#endif // TRIANGLE_H_