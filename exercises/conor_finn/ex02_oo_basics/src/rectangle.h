#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

class Rectangle: public Shape {
  private:
    int side1;
    int side2;
  
  public:
    Rectangle(int s1, int s2);
    double perimiter();
    double area();

};

#endif