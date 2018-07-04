#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <vector>
#include <memory>

int main(int, char **)
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.emplace_back(std::make_unique<Circle>(10));
    shapes.emplace_back(std::make_unique<Square>(10));
    shapes.emplace_back(std::make_unique<Rectangle>(10,10));
    shapes.emplace_back(std::make_unique<Triangle>(10,10));
}