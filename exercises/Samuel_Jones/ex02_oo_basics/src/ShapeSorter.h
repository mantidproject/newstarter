#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "Shape.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ShapeSorter {
private:
  void printShape(Shape const &shape);

public:
  ShapeSorter();
  void printOutShapesOfType(std::vector<std::unique_ptr<Shape>> const &,
                            std::string);
  void printOutShapesOfSides(std::vector<std::unique_ptr<Shape>> const &, int);
  void printOutShapesInOrderOfArea(std::vector<std::unique_ptr<Shape>> &);
  void printOutShapesInOrderOfPerimeter(std::vector<std::unique_ptr<Shape>> &);
};

#endif /*SHAPESORTER_H_*/