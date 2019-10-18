#include "../include/ShapeSorter.h"
#include "../include/Shapes.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Triangle.h"
#include "../include/Circle.h"

using namespace std;
int main(int, char **)
{
    // Create shapes
	auto sCircle_1 = Circle(1.5);
	auto sCircle_2 = Circle(2.5);
	auto sSquare_1 = Square(1.5);
	auto sRectangle_1 = Rectangle(2, 3);
	auto sTriangle_1 = Triangle(2, 3);
    // Shape container
    vector<BaseShape*> shapes;
    shapes.emplace_back(&sCircle_1);
    shapes.emplace_back(&sCircle_2);
    shapes.emplace_back(&sSquare_1);
    shapes.emplace_back(&sRectangle_1);
    shapes.emplace_back(&sTriangle_1);
    //Sort shapes
    ShapeSorter shapeSorter(shapes);
    // Test print functions
    shapeSorter.printShapeByType("Circle");
    shapeSorter.printShapeBySides(4);
    shapeSorter.printShapesByArea();
    shapeSorter.printShapesByPerimeter();

    return 0;
}