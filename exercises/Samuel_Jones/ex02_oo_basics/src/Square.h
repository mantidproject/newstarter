#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square : public Shape {
private:
  int m_side1;

public:
  Square(int);
  double getPerimeter() const;
  double getArea() const;
};

#endif /*SQUARE_H_*/