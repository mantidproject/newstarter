#ifndef TRIANGLE_H
#define TRIANGLE_H

// Includes
#include "Shape.h"

// Class definition
class Triangle : public Shape {
public:
  Triangle();
  Triangle(double h, double w);
  ~Triangle();
  void print();

private:
};

#endif TRIANGLE_H

// End of file