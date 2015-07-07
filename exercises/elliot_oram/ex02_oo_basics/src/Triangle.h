#ifndef TRIANGLE_H
#define TRIANGLE_H

// Includes
#include "Shape.h"

/**
 *A Class used to model a Triangle 
 *Triangle inherits from the Shape super class
 */
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