#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double width, double height);

  double getWidth() const;
  double getHeight() const;
  std::string getType() const override;
  std::size_t getNumberOfEdges() const override;
  double getPerimeter() const override;
  double getArea() const override;

private:
  const double m_width;
  const double m_height;
  const double m_area;
  const double m_perimeter;
};

#endif
