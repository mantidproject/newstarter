#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"

class Triangle: public Shape {
  private:
    int height;
    int base;
  
  public:
    Triangle(int height, int base);
    double perimiter();
    double area();

};

#endif