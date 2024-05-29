//
// Created by gfl56326 on 28/05/2024.
//

#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "Shape.h"
#include <vector>
#include <algorithm>
#include <iostream>

class ShapeSorter {
public:
    void printShapesByType(const std::vector<Shape*>& shapes, const std::string& type);
    void printShapesBySides(const std::vector<Shape*>& shapes, int numberOfSides);
    void printShapesByAreaDescending(std::vector<Shape*>& shapes);
    void printShapesByPerimeterDescending(std::vector<Shape*>& shapes);
};

#endif // SHAPESORTER_H
