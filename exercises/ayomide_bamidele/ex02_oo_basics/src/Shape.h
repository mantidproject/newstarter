#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
private:
 const std::string type = "Shape";

public:
  virtual std::string getType() const = 0;
  virtual int getNoOfSides() const = 0;
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
};
#endif // !SHAPE_H
