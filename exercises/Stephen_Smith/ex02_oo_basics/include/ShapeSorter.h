#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "Shapes.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include <algorithm>
/**
 * This class stores a number of shapes, and provides
 * operations based on the number of sides, area, perimeter,
 * and type of the stored shapes.
 */
class ShapeSorter
{
public:
    // Constructors
    ShapeSorter();
    ShapeSorter(std::vector<BaseShape*> shapeList);
    // Add shapes to object
    void addShape();
    // Print functions
    void PrintShapeNames() const;
    void printShapeByType(const std::string& shapeType) const;
    void printShapeBySides(const int nSides) const ;
    void printShapesByArea() ;
    void printShapesByPerimeter();
private:
     // Vector of shapes sorted within the object
     std::vector<BaseShape*> m_shapeList;
};

#endif