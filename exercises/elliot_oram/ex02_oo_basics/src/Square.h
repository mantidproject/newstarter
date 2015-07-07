#ifndef SQUARE_H
#define SQUARE_H
// Includes
#include "Shape.h"

// Class definition
class Square : public Shape {
public:
  Square();
  Square(const double &h, const double &w);
  ~Square();
  void print();

private:
};

#endif

// End of File