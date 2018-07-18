#ifndef SHAPESORTER_H
#define SHAPESORTER
#include "Shape.h"
#include <string>
#include <vector>

class ShapeSorter {
public:
  int printByType(const std::vector<Shape> &shapes, const std::string &type);
  ~ShapeSorter() = default;
};

#endif // !SHAPESORTER_H
