// Imports
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>

// Namespace to use
using namespace std;

/**
 *  Base class
 **/
class Shape {

// Instance variables
private:
  string shapeType;
  unsigned int numSides;

// Methods
public:
  Shape(const string &type, int sides) {
    shapeType = type;
    numSides = sides;
  }

  // Methods to be overridden
  virtual double perimeter() = 0;
  virtual double area() = 0;

  // Methods for info
  void printType() const {
    cout << "Shape type is: " << getShapeType() << endl;
  }

  virtual void printNumSides() const {
    cout << "Number of sides is: " << getNumSides() << endl;
  }

  // Getters
  string getShapeType() const { return shapeType; }

  int getNumSides() const { return numSides; }

  // Destructor
  virtual ~Shape() {}
};

/**
 *  Square class
 **/
class Square : public Shape {

// Own side length
private:
  double width;

// Method implementations
public:
  // Constructor
  Square(double widthLen) : Shape("Square", 4) { width = widthLen; }

  // Calculates and returns the perimeter
  double perimeter() override { return 4 * width; }

  // Calculates and returns the area
  double area() override { return width * width; }
};

/**
 *  Rectangle class
 **/
class Rectangle : public Shape {

// Own side lengths
private:
  double width;
  double height;

// Method implementations
public:
  // Constructor
  Rectangle(double widthLen, double heightLen) : Shape("Rectangle", 4) {
    width = widthLen;
    height = heightLen;
  }

  // Calculates and returns the perimeter
  double perimeter() override { return (2 * width + 2 * height); }

  // Calculates and returns the area
  double area() override { return width * height; }
};

/**
 *  Circle class
 **/
class Circle : public Shape {

// Own radius
private:
  double radius;

// Method implementations
public:
  // Constructor
  Circle(double radiusLen) : Shape("Circle", 0) { radius = radiusLen; }

  // Calculates and returns the perimeter
  double perimeter() override { return (2 * M_PI * radius); }

  // Calculates and returns the area
  double area() override { return (M_PI * radius * radius); }
};

/**
 *  Triangle class
 **/
class Triangle : public Shape {

// Own height and base
private:
  double height;
  double base;

// Method implementations
public:
  // Constructor
  Triangle(double heightLen, double baseLen) : Shape("Triangle", 3) {
    height = heightLen;
    base = baseLen;
  }

  // Calculates and returns the perimeter
  double perimeter() {
    return (base + 2 * sqrt(height * height + (base * base) / 4));
  }

  // Calculates and returns the area
  double area() { return (0.5 * base * height); }
};

/**
 *  ShapeSorter class
 **/
class ShapeSorter {

  /**
   * Comparators for sort()
   *
   * http://www.cplusplus.com/reference/algorithm/sort/
   **/
  static bool compareArea(Shape *shape1, Shape *shape2) {
    return shape1->area() > shape2->area();
  }

  static bool comparePerimeter(Shape *shape1, Shape *shape2) {
    return shape1->perimeter() > shape2->perimeter();
  }

public:
  // Method to print matching given type
  void printMatchingType(vector<Shape *> shapes, string name) {
    for (vector<Shape *>::const_iterator it = shapes.begin();
         it != shapes.end(); ++it) {
      if (((*it)->getShapeType()).compare(name) == 0) {
        cout << (*it)->getShapeType() << endl;
      }
    }
  }

  // Method to print shapes of chosen number of sides
  void printShapesMatchingNumSides(vector<Shape *> shapes, int numSides) {
    for (vector<Shape *>::const_iterator it = shapes.begin();
         it != shapes.end(); ++it) {
      if (((*it)->getNumSides()) == numSides) {
        cout << (*it)->getShapeType() << endl;
      }
    }
  }

  // Print the shapes by area descending
  void printAreaDescending(vector<Shape *> shapes) {
    vector<Shape *> sortedAreas = shapes;
    sort(sortedAreas.begin(), sortedAreas.end(), ShapeSorter::compareArea);

    for (vector<Shape *>::iterator it = sortedAreas.begin();
         it != sortedAreas.end(); ++it) {
      cout << (*it)->getShapeType() << "\t\t" << (*it)->area() << endl;
    }
  }

  // Print the shapes by perimeter descending
  void printPerimeterDescending(vector<Shape *> shapes) {
    vector<Shape *> sortedPerimeters = shapes;
    sort(sortedPerimeters.begin(), sortedPerimeters.end(),
         ShapeSorter::comparePerimeter);

    for (vector<Shape *>::iterator it = sortedPerimeters.begin();
         it != sortedPerimeters.end(); ++it) {
      cout << (*it)->getShapeType() << "\t\t" << (*it)->perimeter() << endl;
    }
  }
};

/**
 *  Main method
 **/
int main() {
  // Shapes
  Square square(5);
  Rectangle rectangle(5, 10);
  Circle circle(5);
  Triangle triangle(10, 5);

  // Add shapes into a vector
  vector<Shape *> shapes;
  shapes.push_back(&square);
  shapes.push_back(&rectangle);
  shapes.push_back(&circle);
  shapes.push_back(&triangle);

  // Loop through each shape
  for each(Shape * shape in shapes) {
      shape->printType();
      shape->printNumSides();
      cout << "Area: " << shape->area() << endl;
      cout << "Perimeter: " << shape->perimeter() << endl;
      cout << endl;
    }

  // Print chosen types
  cout << "\n\nShape sorting section\n\n" << endl;
  ShapeSorter ss;

  ss.printMatchingType(shapes, "Square");
  cout << endl;
  ss.printShapesMatchingNumSides(shapes, 4);
  cout << endl;
  ss.printAreaDescending(shapes);
  cout << endl;
  ss.printPerimeterDescending(shapes);
  cout << endl;

  return 0;
}
