#ifndef SQUARE_H
#define SQUARE_H
// Includes
#include "Shape.h"

/**
 *A Class used to model a Square
 *Square inherits from the Shape super class
 */
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