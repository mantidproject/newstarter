#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include <vector>
#include <string>
#include "Shape.h"

class ShapeSorter
{
private:
public:
    ShapeSorter();
    void printOutShapesOfType(std::vector<Shape>, std::string);
    void printOutShapesOfSides(std::vector<Shape>, int);
    void printOutShapesInOrderOfVolume(std::vector<Shape>);
    void printOutShapesInOrderOfPerimeter(std::vector<Shape>);
};

#endif /*SHAPESORTER_H_*/