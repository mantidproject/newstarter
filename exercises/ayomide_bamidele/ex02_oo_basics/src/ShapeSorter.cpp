#include "ShapeSorter.h"
#include "Shape.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int ShapeSorter::printByType(const std::vector<Shape*> &shapes,
                             const std::string &type) {
  for (const auto &shape : shapes) {
    if (shape->getType() == type) {
      std::cout << shape->getType() << "has the right type" << std::endl;
    }
  }
  return 0;
}

int ShapeSorter::printBySide(const std::vector<Shape*> &shapes,
                             const int &noOfSides) {
  for (const auto &shape : shapes) {
    if (shape->getNoOfSides() == noOfSides) {
      std::cout << shape->getType() << "has " << noOfSides << std::endl;
    }
  }
  return 0;
}

int ShapeSorter::printByVolume(std::vector<Shape*> shapes) {

  std::sort(shapes.begin(), shapes.end(),
            [](Shape* &a, Shape* &b) { return a->area() < b->area(); });

  for (const auto &shape : shapes) {
    std::cout << shape->getType() << std::endl;
  }
  return 0;
}

int ShapeSorter::printByPerimeter(std::vector<Shape*> shapes) {

  std::sort(shapes.begin(), shapes.end(),
            [](Shape* &a, Shape* &b) { return a->perimeter() < b->perimeter(); });

  for (const auto &shape : shapes) {
    std::cout << shape->getType() << std::endl;
  }
  return 0;
}
