/*
* File:   main.cpp
* Author: Elliot Oram
*/

// Includes
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ShapeSorter.h"
#include "Square.h"
#include "Triangle.h"

#include <iostream>
#include <vector>

// Member Functions

/**
 *Adds a shape to the back of the shape vector
 *@param shapes The vector containing all shapes
 *@param s A pointer to the new shape to be added
 *@return The vector of all the shapes with the new shape added
 */
std::vector<Shape *> addShape(std::vector<Shape *> shapes, Shape *s) {
  shapes.push_back(s);
  std::cout << "A " << s->getType() << " has been added to the list."
            << std::endl;
  return shapes;
}

/**
 *Prints a list of all the shapes in the vector
 *@param shapes A vector of all the shapes
 */
void printAllShapes(std::vector<Shape *> shapes) {
  for (int i = 0; i < shapes.size(); i++) {
    shapes[i]->print();
  }
}

// Main
int main(int, char **) {

  ShapeFactory *factory = new ShapeFactory();
  Square *s = factory->createSquare(2);
  Circle *c = factory->createCircle(3);
  Triangle *t = factory->createTriangle(5, 2);
  Rectangle *r = factory->createRectangle(3, 4);

  std::vector<Shape *> shapes;
  shapes = addShape(shapes, s);
  shapes = addShape(shapes, c);
  shapes = addShape(shapes, t);
  shapes = addShape(shapes, r);

  ShapeSorter *shapeSort = new ShapeSorter(shapes);
  shapeSort->printByType("Rectangle");
  shapeSort->printBySide(4);
  shapeSort->printByPerimeter();
  shapeSort->printByVolume();

  std::system("PAUSE");
}

// End of file