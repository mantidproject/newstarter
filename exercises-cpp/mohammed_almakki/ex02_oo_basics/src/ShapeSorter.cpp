#include "ShapeSorter.h"

void ShapeSorter::filterAndPrintByPredicate(const std::vector<std::shared_ptr<Shape>> &shapes, const ShapeFilterPredicate &predicate) const
{
    for_each(
        shapes.begin(), shapes.end(), [predicate](auto shape)
        {
            if(predicate(shape)) {
                std::cout << shape->toString() << " ";
            } });
    std::cout << "\n";
}

void ShapeSorter::printShapesWithType(const ShapeType &type) const
{
    filterAndPrintByPredicate(shapes, [type](const std::shared_ptr<Shape> &shape)
                              { return shape->getType() == type; });
}

void ShapeSorter::printShapesWithSides(const int &sidesCount) const
{
    filterAndPrintByPredicate(shapes, [sidesCount](const std::shared_ptr<Shape> &shape)
                              { return shape->getSidesCount() == sidesCount; });
}

void ShapeSorter::printOrderedShapesByArea() const
{
    auto sortedShapes = shapes;

    std::sort(
        sortedShapes.begin(), sortedShapes.end(),
        [](auto left, auto right)
        {
            return left->getArea() > right->getArea();
        });

    filterAndPrintByPredicate(sortedShapes, [](const std::shared_ptr<Shape> &shape)
                              { return true; });
}

void ShapeSorter::printOrderedShapesByPerimeter() const
{
    auto sortedShapes = shapes;

    std::sort(
        sortedShapes.begin(), sortedShapes.end(),
        [](auto left, auto right)
        {
            return left->getPerimeter() > right->getPerimeter();
        });

    filterAndPrintByPredicate(sortedShapes, [](const std::shared_ptr<Shape> &shape)
                              { return true; });
}