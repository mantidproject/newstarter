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
  const double m_radius;
  const double m_area;
  const double m_perimeter;
};

#endif
