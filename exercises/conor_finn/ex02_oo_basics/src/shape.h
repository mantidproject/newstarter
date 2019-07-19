#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

class Shape {
private:
  const int m_sides;
  const std::string m_name;

public:
  Shape(int s, std::string n);

  // Pure virtual functions. Overidden.
  virtual double perimiter() const = 0;
  virtual double area() const = 0;

  int getNumberOfSides() const;
  std::string getName() const;
  void printInfo() const;
};

#endif // SHAPE_H_