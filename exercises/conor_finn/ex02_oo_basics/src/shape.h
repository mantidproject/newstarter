#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {
private:
  int sides;
  std::string name;

public:
  Shape(int s, std::string n);
  Shape() : sides(0), name("") {}

  // Pure virtual functions. Overidden.
  virtual double perimiter() = 0;
  virtual double area() = 0;

  int getSides();
  std::string getName();
  void printInfo();
};

#endif