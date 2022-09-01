/**
 * Skeleton main routine
 */
#include <iostream>
#include <vector>
#include "Square.h"
#include "Rectangle.h"
#include "ShapeSorter.h"
#include "Circle.h"
#include "Triangle.h"


int main(int, char **)
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle{ 10, 3 });
    shapes.push_back(new Square{ 2.5 });
    shapes.push_back(new Rectangle{ 50, 50 });
    shapes.push_back(new Rectangle{ 20, 1 });
    shapes.push_back(new Circle{ 3 });
    shapes.push_back(new Circle{ 50 });
    shapes.push_back(new Triangle{ 5, 2 });
    shapes.push_back(new Triangle{ 7, 3 });
    std::cout << "By Area Dec \n";
    ShapeSorter().print_byarea_dec(shapes);
    std::cout << "By Perimeter Dec \n";
    ShapeSorter().print_byperimeter_dec(shapes);
    std::cout << "Only Print Rectangle \n";
    ShapeSorter().print_type(shapes, "Rectangle");
    std::cout << "Only Print Circle \n";
    ShapeSorter().print_type(shapes, "Circle");
    std::cout << "Only Print side 4 \n";
    ShapeSorter().print_sides(shapes, 4);
    std::cout << "Only Print side 1 \n";
    ShapeSorter().print_sides(shapes, 1);
    std::cout << "Only Print side 3 \n";
    ShapeSorter().print_sides(shapes, 3);
}