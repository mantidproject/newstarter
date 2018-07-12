#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape {
public:
  Triangle(double base, double height);

  double getBase() const;
  double getHeight() const;
  std::string getType() const override;
  std::size_t getNumberOfEdges() const override;
  double getArea() const override;
  double getPerimeter() const override;

private:
  double const m_base;
  double const m_height;
  double const m_area;
  double const m_perimeter;
};

#endif
