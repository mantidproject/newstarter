#pragma once

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Shape.h"

typedef std::function<bool(const std::shared_ptr<Shape>&)> ShapeFilterPredicate;

class ShapeSorter
{
public:
    ShapeSorter(const std::vector<std::shared_ptr<Shape>> &shapes) : shapes{shapes} {}

    void printShapesWithType(const ShapeType &type) const;
    void printShapesWithSides(const int &sidesCount) const;
    void printOrderedShapesByArea() const;
    void printOrderedShapesByPerimeter() const;

private:
    void filterAndPrintByPredicate(const std::vector<std::shared_ptr<Shape>> &, const ShapeFilterPredicate&) const;
    const std::vector<std::shared_ptr<Shape>> &shapes;
};
