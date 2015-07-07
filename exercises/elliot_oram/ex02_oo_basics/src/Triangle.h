#ifndef TRIANGLE_H
#define TRIANGLE_H

// Includes
#include "Shape.h"

// Class definition
class Triangle : public Shape {
public:
  Triangle();
  Triangle(const double &h, const double &w);
  ~Triangle();
  void print();

private:
};

#endif

// End of file