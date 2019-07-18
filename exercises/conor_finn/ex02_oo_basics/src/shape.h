#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {
private:
  const int sides;
  const std::string name;

public:
  Shape(int s, std::string n);

  // Pure virtual functions. Overidden.
  virtual double perimiter() const = 0;
  virtual double area() const = 0;

  int getNumberOfSides() const;
  std::string getName() const;
  void printInfo() const;
};

#endif