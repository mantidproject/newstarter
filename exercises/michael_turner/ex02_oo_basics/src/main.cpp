/**
 * Initialises 4 types of shape (Circle, Rectangle, Square & Triangle).
 *
 * Shapes are then sorted by area, perimeter, type & number of sides.
 */


//Includes
#include "shapes.h"
#include "shape_sorter.h"

#include <iostream>
#include <vector>

int main(){

    //Prevent Object slicing
    std::vector<std::reference_wrapper<Shape>> shapes;
    //Initialise shapes
    Circle a(1.5);
    Square b(5);
    Triangle c(3,7.9);
    Rectangle d(3,5.5);
    Triangle e(1, 5);
    Square f(3);
    Rectangle g(4,0.5);
    Triangle h(1.1,11);
    shapes.push_back(a);
    shapes.push_back(b);
    shapes.push_back(c);
    shapes.push_back(d);
    shapes.push_back(e);
    shapes.push_back(f);
    shapes.push_back(g);
    shapes.push_back(h);

    //Initialises Shapesorter object, which allows the sorting of shapes
    ShapeSorter sort(shapes);

    sort.area();
    sort.types("square");
    sort.sides(4);
    sort.perim();

    return 0;
}
