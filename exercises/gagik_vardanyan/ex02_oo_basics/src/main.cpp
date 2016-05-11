/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>
#include "include/Circle.h"
#include "include/Rectangle.h"
#include "include/Shape.h"
#include "include/ShapeSorter.h"
#include "include/Square.h"
#include "include/Triangle.h"

int main(int argc, char ** argv)
{
    std::vector<Shape> shapes;

    Rectangle * rect = new Rectangle(10,50);
    Triangle * tri = new Triangle(10,5);
    Square * sq = new Square(7);
    Circle * cq = new Circle(5);

    Shape sh1(rect);
    Shape sh2(tri);
    Shape sh3(sq);
    Shape sh4(cq);

    shapes.push_back(sh1);
    shapes.push_back(sh2);
    shapes.push_back(sh3);
    shapes.push_back(sh4);

    std::cout << "++++++++Original++++++++\n";

    ShapeSorter ss(shapes);
    ss.Print(std::cout);

    std::cout << "+++Sorted By Perimeter++\n";

    ss.SortByPerimeter();
    ss.Print(std::cout);

    std::cout << "+++++Sorted By Area+++++\n";

    ss.SortByArea();
    ss.Print(std::cout);

    std::cout << "+++++++Triangles++++++++\n";

    ss.SelectByType(std::string("Triangle"));
    ss.Print(std::cout);

    return 0;
}
