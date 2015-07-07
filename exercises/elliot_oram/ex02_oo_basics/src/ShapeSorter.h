#ifndef SHAPESORTER_H
#define SHAPESORTER_H

// Includes
#include "Shape.h"

#include <vector>

/**
 *A Class used to allow the sorting of a vector of shapes in various ways
 */
class ShapeSorter {
public:
  ShapeSorter();
  ShapeSorter(std::vector<Shape *> s);
  ~ShapeSorter();
  void noMatchFound(const std::string &search);
  void showingShapesBy(const std::string &set, const std::string &feature);
  void printByType(const std::string &type);
  void printBySide(const int &sides);
  void printByVolume();
  void printByPerimeter();
  void updateShapes(const std::vector<Shape *> &s);
  void printAll();
  std::vector<Shape *> getShapes();
  static bool compareVolume(Shape *first, Shape *second);
  static bool comparePerimeter(Shape *first, Shape *second);

private:
  std::vector<Shape *> allShapes;
};
#endif
// End of File