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

/**
 *Called when no matching criteria is found for a search
 *@param search The criteria for the search
 */
void ShapeSorter::noMatchFound(const std::string &search) {
  std::cout << std::endl
            << "No shapes were found that match your search for \"" << search
            << "\"" << std::endl;
}

/**
 *Informs user of the current search Criteria
 *@param set The set of shapes being searched
 *@param feature The exact feature within that set being searched
 */
void ShapeSorter::showingShapesBy(const std::string &set,
                                  const std::string &feature) {
  std::cout << std::endl
            << "Showing Shapes sorted by \"" << set << " - " << feature << "\""
            << std::endl
            << std::endl;
}

/**
 *Prints all the shapes of a given Type
 *@param type The type of shapes that are being searched
 */
void ShapeSorter::printByType(const std::string &type) {
  showingShapesBy("Type", type);
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
    noMatchFound("Type");
  }
}

/**
 *Prints all the shapes that have a given number of sides
 *@param sides The number of sides that are being searched for
 */
void ShapeSorter::printBySide(const int &sides) {
  const std::string sidesString = std::to_string(sides);
  showingShapesBy("Sides", sidesString);
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
    noMatchFound("Sides");
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
  showingShapesBy("Area", "Descending");
  printAll();
}

/**
 *Sorts the list of shapes by perimeter then calls print
 */
void ShapeSorter::printByPerimeter() {
  std::vector<Shape *> sortByP = getShapes();
  std::sort(sortByP.begin(), sortByP.end(), comparePerimeter);
  updateShapes(sortByP);
  showingShapesBy("Perimeter", "Descending");
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