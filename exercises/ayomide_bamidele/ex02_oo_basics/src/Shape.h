#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
private:
  std::string type = "Shape";

public:
  Shape();
  ~Shape() = default;
};
#endif // !SHAPE_H
