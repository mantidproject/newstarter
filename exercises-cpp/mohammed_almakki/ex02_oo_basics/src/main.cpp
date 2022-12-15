#include <iostream>
#include <vector>
#include "Shape.h"
#include "ShapeSorter.h"

int main(int, char **)
{
    Shape *sq1 = new Square(2);

    Shape *rect1 = new Rectangle(2, 4);
    Shape *rect2 = new Rectangle(4, 14);

    Shape *c1 = new Circle(2);
    Shape *c2 = new Circle(10);

    Shape *t1 = new Triangle(2, 4);
    Shape *t2 = new Triangle(4, 10);

    std::vector<Shape *> shapes;

    shapes.push_back(sq1);
    shapes.push_back(rect1);
    shapes.push_back(rect1);
    shapes.push_back(c1);
    shapes.push_back(c2);
    shapes.push_back(t1);
    shapes.push_back(t2);

    ShapeSorter sorter(shapes);
    sorter.printShapesWithType("Rectangle");
    sorter.printShapesWithSides(2);
    sorter.printOrderedShapesByArea();
    sorter.printOrderedShapesByPerimeter();

    return 0;
}