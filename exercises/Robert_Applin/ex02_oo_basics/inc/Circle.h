#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape {
public:
  Circle(double radius);

  std::string getType() const override;
  std::size_t getNumberOfEdges() const override;
  double getPerimeter() const override;
  double getArea() const override;

private:
  double const m_radius;
  double const m_area;
  double const m_perimeter;
};

#endif
