/**
 * Skeleton main routine
 */
#include <iostream>


using namespace std;


#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"
#include <vector>

int main() {
    // Create shapes
    Square square(5.0);
   square.calculateArea();

    Rectangle rectangle(4.0, 6.0);
    rectangle.calculateArea();
    Circle circle(3.0);
    Triangle triangle(4.0, 6.0);

    std::vector<Shape*> shapes;
    shapes.push_back(&square);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);

    ShapeSorter sorter;

    // Print shapes by type
    std::cout << "Shapes of type 'Square':" << std::endl;
    sorter.printShapesByType(shapes, "Square");

    // Print shapes by number of sides
    std::cout << "\nShapes with 4 sides:" << std::endl;
    sorter.printShapesBySides(shapes, 4);

    // Print shapes by area descending
    std::cout << "\nShapes sorted by area (descending):" << std::endl;
    sorter.printShapesByAreaDescending(shapes);

    // Print shapes by perimeter descending
    std::cout << "\nShapes sorted by perimeter (descending):" << std::endl;
    sorter.printShapesByPerimeterDescending(shapes);
}


