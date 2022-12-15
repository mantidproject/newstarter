#include <iostream>
#include <vector>
#include <memory>
#include "Shape.h"
#include "ShapeSorter.h"

int main(int, char **)
{
    auto sq1 = std::make_shared<Square>(2);

    auto rect1 = std::make_shared<Rectangle>(2, 4);
    auto rect2 = std::make_shared<Rectangle>(4, 14);

    auto c1 = std::make_shared<Circle>(2);
    auto c2 = std::make_shared<Circle>(10);

    auto t1 = std::make_shared<Triangle>(2, 4);
    auto t2 = std::make_shared<Triangle>(4, 10);

    std::vector<std::shared_ptr<Shape>> shapes;

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