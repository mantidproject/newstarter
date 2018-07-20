#ifndef SHAPESORTER_H
#define SHAPESORTER
#include "Shape.h"
#include <string>
#include <vector>

class ShapeSorter {
public:
  void printByType(const std::vector<Shape*> &shapes, const std::string &type);
  void printBySide(const std::vector<Shape*> &shapes, const int &noOfSides);
  void printByVolume(std::vector<Shape*> shapes);
  void printByPerimeter(std::vector<Shape*> shapes);
};

#endif // !SHAPESORTER_H
