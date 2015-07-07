// Includes
#include "Shape.h"
#include "ShapeSorter.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// Constructors
ShapeSorter::ShapeSorter() {}

ShapeSorter::ShapeSorter(std::vector<Shape *> s) { allShapes = s; }

ShapeSorter::~ShapeSorter() {}

// Member Fuctions
void ShapeSorter::printByType(const std::string &type) {
  std::cout << std::endl
            << "Sorting shapes by type: \"" << type << "\"..." << std::endl
            << std::endl;
  std::vector<Shape *> allShapes = getShapes();
  int printed = 0;
  const size_t size = allShapes.size();
  for (int i = 0; i < size; i++) {
    if ((allShapes[i]->getType().compare(type)) == 0) {
      allShapes[i]->print();
      printed++;
    }
  }
  if (printed == 0) {
    std::cout << "No shapes were found that match the type: \"" << type << "\""
              << std::endl;
  }
}

void ShapeSorter::printBySide(const int &sides) {
  std::cout << std::endl
            << "Sorting shapes with \"" << sides << "\" sides..." << std::endl
            << std::endl;
  std::vector<Shape *> allShapes = getShapes();
  int printed = 0;
  const size_t size = allShapes.size();
  for (int i = 0; i < size; i++) {
    if (allShapes[i]->getSides() == sides) {
      allShapes[i]->print();
      printed++;
    }
  }
  if (printed == 0) {
    std::cout << "No shapes were found that have \"" << sides
              << "\" number of sides" << std::endl;
  }
}

/**
 *Compares the volume of two shapes
 *@param first The first Shape to be compared
 *@param second The second Shape to be compared
 *@return 0 if shapes are equal, 1 if first > second, -1 if second > first
 */
bool ShapeSorter::compareVolume(Shape *first, Shape *second) {
  return first->getArea() > second->getArea();
}

/**
 *Compares the perimeter of two shapes
 *@param first The first Shape to be compared
 *@param second The second Shape to be compared
 *@return 0 if shapes are equal, 1 if first > second, -1 if second > first
 */
bool ShapeSorter::comparePerimeter(Shape *first, Shape *second) {
  return first->getPerimeter() > second->getPerimeter();
}

/**
 *Sorts the list of shapes by volume then calls print
 */
void ShapeSorter::printByVolume() {
  std::vector<Shape *> sortByV = getShapes();
  std::sort(sortByV.begin(), sortByV.end(), compareVolume);
  updateShapes(sortByV);
  std::cout << std::endl
            << "Showing Shapes sorted by Area" << std::endl
            << std::endl;
  printAll();
}

/**
 *Sorts the list of shapes by perimeter then calls print
 */
void ShapeSorter::printByPerimeter() {
  std::vector<Shape *> sortByP = getShapes();
  std::sort(sortByP.begin(), sortByP.end(), comparePerimeter);
  updateShapes(sortByP);
  std::cout << std::endl
            << "Showing Shapes sorted by Perimeter" << std::endl
            << std::endl;
  printAll();
}

/**
 *Prints the list of all the shapes
 */
void ShapeSorter::printAll() {
  std::vector<Shape *> allShapes = getShapes();
  if (allShapes.size() == 0) {
    std::cout << "The list of shapes is empty";
  } else {
    for (int i = 0; i < allShapes.size(); i++) {
      allShapes[i]->print();
    }
  }
}

// Accessors
std::vector<Shape *> ShapeSorter::getShapes() { return allShapes; }

// Mutators
void ShapeSorter::updateShapes(const std::vector<Shape *> &s) { allShapes = s; }

// End of File