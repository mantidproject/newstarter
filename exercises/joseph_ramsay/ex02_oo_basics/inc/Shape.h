#ifndef SHAPE_H
#define SHAPE_H

#include <string>

enum class ShapeType { square, circle, rectangle, triangle };

class Shape {

public:
  virtual ~Shape();
  virtual int getNumSides() const = 0;
  virtual double getArea() const = 0;
  virtual double getPerimeter() const = 0;
  virtual ShapeType getType() const = 0;
  virtual std::string toString() const = 0;
};

#endif
