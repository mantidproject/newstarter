#ifndef CIRCLE_H
#define CIRCLE_H


#include "shape.h"


class Circle: public Shape{

  
private:
  int m_radius;

  
public:
  Circle(int radius);
  int getNumSides() const;
  double getArea() const;
  double getPerimeter() const;
  ShapeType getType() const;
  std::string toString() const;

  
};


#endif
