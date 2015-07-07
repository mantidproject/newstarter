#ifndef SHAPE_H
#define SHAPE_H
// Includes
#include <string>

/**
 *A Class used to model a generic shape
 */
class Shape {
public:
  Shape();
  Shape(const std::string &t, const int &s);
  ~Shape();

  std::string getType();
  int getSides();
  double getArea();
  double getPerimeter();
  double getHeight();
  double getWidth();
  void setType(const std::string &t);
  void setSides(const int &s);
  void setArea(const double &a);
  void setPerimeter(const double &p);
  void setWidth(const double &w);
  void setHeight(const double &h);
  virtual void print();

private:
  std::string type;
  int sides;
  double area, perimeter, height, width;
};

// End of File

#endif