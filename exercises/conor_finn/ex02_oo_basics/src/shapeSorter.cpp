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
void ShapeSorter::printMatchingName(const std::vector<Shape *> &shapes,
                                    const std::string &n) {
  int counter = 1;
  for (auto i = shapes.begin(); i != shapes.end(); i++) {
    if ((*i)->getName() == n) {
      std::cout << "Shape " << counter << ":\n";
      (*i)->printInfo();
      ++counter;
    }
  }
}

/**
 * @brief Print out details for shapes with a given number of sides.
 *
 * @param shapes Vector of shape pointers.
 * @param n Number of sides to match.
 */
void ShapeSorter::printMatchingSides(const std::vector<Shape *> &shapes,
                                     const int &n) {
  int counter = 1;
  for (auto i = shapes.begin(); i != shapes.end(); i++) {
    if ((*i)->getSides() == n) {
      std::cout << "Shape " << counter << ":\n";
      (*i)->printInfo();
      ++counter;
    }
  }
}

/**
 * @brief Print details of shapes ordered by area.
 *
 * @param shapes A vector of shape pointers.
 */
void ShapeSorter::printOrderedByArea(std::vector<Shape *> shapes) {
  std::sort(shapes.begin(), shapes.end(),
            [](Shape *a, Shape *b) { return a->area() > b->area(); });
  int counter = 1;
  for (auto i = shapes.begin(); i != shapes.end(); i++) {
    std::cout << "Shape " << counter << ":\n";
    (*i)->printInfo();
    ++counter;
  }
}

/**
 * @brief Print details of shapes ordered by area.
 *
 * @param shapes A vector of shape pointers.
 */
void ShapeSorter::printOrderedByPerimiter(std::vector<Shape *> shapes) {
  std::sort(shapes.begin(), shapes.end(),
            [](Shape *a, Shape *b) { return a->perimiter() > b->perimiter(); });
  int counter = 1;
  for (auto i = shapes.begin(); i != shapes.end(); i++) {
    std::cout << "Shape " << counter << ":\n";
    (*i)->printInfo();
    ++counter;
  }
}