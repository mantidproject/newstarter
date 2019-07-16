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
 * @brief Compariton method for the area of shape pointers.
 *
 * @param a The first shape pointer.
 * @param b The second shape pointer.
 * @return true If the first shape has a larger area than the second.
 * @return false If the first has a smaller or equal area.
 */
bool ShapeSorter::compareArea(Shape *&a, Shape *&b) {
  return (a->area() > b->area());
}

/**
 * @brief Comparison method for the perimiter of shapes.
 *
 * @param a Pointer to the first shape.
 * @param b Pointer to the second shape.
 * @return true If a has a larger perimiter than b.
 * @return false If a has a smaller or equal perimiter to b.
 */
bool ShapeSorter::comparePerimiter(Shape *&a, Shape *&b) {
  return (a->perimiter() > b->perimiter());
}

/**
 * @brief Print details of shapes ordered by area.
 *
 * @param shapes A vector of shape pointers.
 */
void ShapeSorter::printOrderedByArea(std::vector<Shape *> shapes) {
  std::sort(shapes.begin(), shapes.end(), compareArea);
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
  std::sort(shapes.begin(), shapes.end(), comparePerimiter);
  int counter = 1;
  for (auto i = shapes.begin(); i != shapes.end(); i++) {
    std::cout << "Shape " << counter << ":\n";
    (*i)->printInfo();
    ++counter;
  }
}