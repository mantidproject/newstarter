#include "shapeSorter.h"
#include "shape.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Print out the details for all shapes with a given name.
 *
 * @param shapes Vector containing pointers to the shapes.
 * @param n The name to match.
 */
void ShapeSorter::printMatchingName(const std::vector<const Shape *> &shapes,
                                    const std::string &n) {
  std::vector<const Shape *> matching(shapes.size());
  auto it = std::copy_if(shapes.begin(), shapes.end(), matching.begin(),
                         [n](const Shape *s) { return (s->getName()) == n; });
  matching.resize(std::distance(matching.begin(), it));
  printShapes(matching);
}

/**
 * @brief Print out details for shapes with a given number of sides.
 *
 * @param shapes Vector of shape pointers.
 * @param n Number of sides to match.
 */
void ShapeSorter::printMatchingSides(const std::vector<const Shape *> &shapes,
                                     const int &n) {
  std::vector<const Shape *> matching(shapes.size());
  auto it =
      std::copy_if(shapes.begin(), shapes.end(), matching.begin(),
                   [n](const Shape *s) { return s->getNumberOfSides() == n; });
  matching.resize(std::distance(matching.begin(), it));
  printShapes(matching);
}

/**
 * @brief Print details of shapes ordered by area.
 *
 * @param shapes A vector of shape pointers.
 */
void ShapeSorter::printOrderedByArea(std::vector<const Shape *> shapes) {
  std::sort(shapes.begin(), shapes.end(), [](const Shape *a, const Shape *b) {
    return a->area() > b->area();
  });
  printShapes(shapes);
}

/**
 * @brief Print details of shapes ordered by area.
 *
 * @param shapes A vector of shape pointers.
 */
void ShapeSorter::printOrderedByPerimiter(std::vector<const Shape *> shapes) {
  std::sort(shapes.begin(), shapes.end(), [](const Shape *a, const Shape *b) {
    return a->perimiter() > b->perimiter();
  });
  printShapes(shapes);
}

/**
 * @brief Print the some info about the shapes from a vector.
 *
 * @param shapes
 */
void ShapeSorter::printShapes(std::vector<const Shape *> &shapes) {
  int counter = 1;
  for (const auto &i : shapes) {
    std::cout << "Shape " << counter << ":\n";
    i->printInfo();
    ++counter;
  }
}