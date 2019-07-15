#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "shape.h"

class Circle: public Shape {
  private:
    int radius;
  
  public:
    Circle(int radius);
    double perimiter();
    double area();
};

#endif