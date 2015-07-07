#ifndef CIRCLE_H
#define CIRCLE_H
// Includes
#include "Shape.h"

/**
 *A Class used to model a Circle 
 *Circle inherits from the Shape super class
 */
class Circle : public Shape {
public:
  Circle();
  Circle(const double &r);
  ~Circle();
  void print();

private:
};

#endif

// End of File