/**
 * Skeleton main routine
 */

#include "../include/ShapeSorter.h"


using namespace std;
int main(int, char **)
{

    // Create shapes
    auto sCircle_1 = make_shared<Circle>(1.5);
    auto sCircle_2 = make_shared<Circle>(2.5);
    auto sSquare_1 = make_shared<Square>(2);
    auto sRectangle_1 = make_shared<Rectangle>(2,3);
    auto sTriangle_1 = make_shared<Triangle>(1.5,1.5);
 
    // Shape container
    std::vector<shared_ptr<BaseShape>> shapes;
    shapes.emplace_back(sCircle_1);
    shapes.emplace_back(sCircle_2);
    shapes.emplace_back(sSquare_1);
    shapes.emplace_back(sRectangle_1);
    shapes.emplace_back(sTriangle_1);


    // Sort shapes
    ShapeSorter shapeSorter(shapes);

    // Test print functions
    shapeSorter.printShapeByType("Circle");
    shapeSorter.printShapeBySides(4);
    shapeSorter.printShapesByArea();
    shapeSorter.printShapesByPerimeter();



    return 0;
}