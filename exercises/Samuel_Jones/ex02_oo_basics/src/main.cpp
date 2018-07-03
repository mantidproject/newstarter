#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <vector>

int main(int, char **)
{
    std::vector<Shape> shapes;
    shapes.push_back(Circle(10));
    shapes.push_back(Square(10));
    shapes.push_back(Rectangle(10,10));
    shapes.push_back(Triangle(10,10));
}