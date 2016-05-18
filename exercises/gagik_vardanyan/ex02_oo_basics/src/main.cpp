/*!
 * Program that creates various shapes.
 */

#include <iostream>
#include <vector>
#include "include/Circle.h"
#include "include/Rectangle.h"
#include "include/Shape.h"
#include "include/ShapeSorter.h"
#include "include/Square.h"
#include "include/Triangle.h"

///the main program
int main(int argc, char ** argv)
{
    std::vector<Shape*> shapes;

    Rectangle * rect = new Rectangle(10,50);
    Triangle * tri = new Triangle(10,5);
    Square * sq = new Square(7);
    Circle * cq = new Circle(5);

    shapes.push_back(rect);
    shapes.push_back(tri);
    shapes.push_back(sq);
    shapes.push_back(cq);

    ShapeSorter ss(shapes);

    std::cout << "++++++++Original++++++++\n";

    ss.PrintAll(std::cout);

    std::cout << "+++Sorted By Perimeter++\n";

    ss.PrintSortByPerimeter(std::cout);

    std::cout << "+++++Sorted By Area+++++\n";

    ss.PrintSortByArea(std::cout);

    std::cout << "+++++++Triangles++++++++\n";

    ss.PrintSelectByType(std::cout, std::string("Triangle"));

    return 0;
}
