#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "Shapes.h"
#include <algorithm>


class ShapeSorter
{
    public:

    // Constructors
    ShapeSorter();
    ShapeSorter(const std::vector<std::shared_ptr<BaseShape>>& shapeList);

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
        std::vector<std::shared_ptr<BaseShape>> m_shapeList;
};










#endif