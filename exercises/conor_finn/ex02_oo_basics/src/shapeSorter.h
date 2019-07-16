#ifndef SHAPE_SORTER_H_
#define SHAPE_SORTER_H_

#include "shape.h"
#include <vector>

class ShapeSorter {
public:
  static void printMatchingName(const std::vector<Shape *> &shapes,
                                const std::string &name);
  static void printMatchingSides(const std::vector<Shape *> &shapes,
                                 const int &sides);
  static void printOrderedByArea(std::vector<Shape *>);
  static void printOrderedByPerimiter(std::vector<Shape *>);
};

#endif