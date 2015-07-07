#ifndef CIRCLE_H
#define CIRCLE_H
// Includes
#include "Shape.h"

// Class definition
class Circle : public Shape {
public:
  Circle();
  Circle(double r);
  ~Circle();
  void print();

private:
};

#endif

// End of File