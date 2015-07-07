#ifndef SQUARE_H
#define SQUARE_H
// Includes
#include "Shape.h"

// Class definition
class Square : public Shape {
public:
  Square();
  Square(double h, double w);
  ~Square();
  void print();

private:
};

#endif SQUARE_H

// End of File