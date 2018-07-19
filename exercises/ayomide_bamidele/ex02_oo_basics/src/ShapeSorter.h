#ifndef SHAPESORTER_H
#define SHAPESORTER
#include "Shape.h"
#include <string>
#include <vector>

class ShapeSorter {
public:
  int printByType(const std::vector<Shape*> &shapes, const std::string &type);
  int printBySide(const std::vector<Shape*> &shapes, const int &noOfSides);
  int printByVolume(std::vector<Shape*> shapes);
  int printByPerimeter(std::vector<Shape*> shapes);
  ~ShapeSorter() = default;
};

#endif // !SHAPESORTER_H
