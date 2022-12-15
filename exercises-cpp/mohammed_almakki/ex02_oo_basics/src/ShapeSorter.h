#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Shape.h"

class ShapeSorter
{
public:
    ShapeSorter(const std::vector<std::shared_ptr<Shape>> &shapes) : shapes{shapes} {}

    void printShapesWithType(const std::string &type)
    {
        for (auto shape : shapes)
        {
            if (shape->getType() == type)
            {
                std::cout << shape->toString() << " ";
            }
        }
        std::cout << "\n";
    }

    void printShapesWithSides(const int &sidesCount)
    {
        for (auto shape : shapes)
        {
            if (shape->getSidesCount() == sidesCount)
            {
                std::cout << shape->toString() << " ";
            }
        }
        std::cout << "\n";
    }

    void printOrderedShapesByArea()
    {
        auto sortedShapes = shapes;

        std::sort(
            sortedShapes.begin(), sortedShapes.end(),
            [](auto left, auto right)
            {
                return left->getArea() > right->getArea();
            });

        for (auto shape : sortedShapes)
        {
            std::cout << shape->toString() << " ";
        }
        std::cout << "\n";
    }

    void printOrderedShapesByPerimeter()
    {
        auto sortedShapes = shapes;

        std::sort(
            sortedShapes.begin(), sortedShapes.end(),
            [](auto left, auto right)
            {
                return left->getPerimeter() > right->getPerimeter();
            });

        for (auto shape : sortedShapes)
        {
            std::cout << shape->toString() << " ";
        }
        std::cout << "\n";
    }

private:
    const std::vector<std::shared_ptr<Shape>> &shapes;
};
