#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {
public:
  virtual std::string getType() const = 0;
  virtual std::size_t getNumberOfEdges() const = 0;
  virtual double getPerimeter() const = 0;
  virtual double getArea() const = 0;
};

#endif
