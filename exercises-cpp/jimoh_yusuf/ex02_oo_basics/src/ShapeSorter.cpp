//
// Created by gfl56326 on 28/05/2024.
//

#include "ShapeSorter.h"

void ShapeSorter::printShapesByType(const std::vector<Shape*>& shapes, const std::string& type) {
    for (const auto& shape : shapes) {
        if (shape->getType() == type) {
            std::cout << shape->getType() << " with area: " << shape->calculateArea() << " and perimeter: " << shape->calculatePerimeter() << std::endl;
        }
    }
}

void ShapeSorter::printShapesBySides(const std::vector<Shape*>& shapes, int numberOfSides) {
    for (const auto& shape : shapes) {
        if (shape->getNumberOfSides() == numberOfSides) {
            std::cout << shape->getType() << " with area: " << shape->calculateArea() << " and perimeter: " << shape->calculatePerimeter() << std::endl;
        }
    }
}

void ShapeSorter::printShapesByAreaDescending(std::vector<Shape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->calculateArea() > b->calculateArea();
    });

    for (const auto& shape : shapes) {
        std::cout << shape->getType() << " with area: " << shape->calculateArea() << " and perimeter: " << shape->calculatePerimeter() << std::endl;
    }
}

void ShapeSorter::printShapesByPerimeterDescending(std::vector<Shape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->calculatePerimeter() > b->calculatePerimeter();
    });

    for (const auto& shape : shapes) {
        std::cout << shape->getType() << " with area: " << shape->calculateArea() << " and perimeter: " << shape->calculatePerimeter() << std::endl;
    }
}

