#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "shapes.h"

#include <functional>
#include <map>
#include <string>
#include <vector>

/// Class that can sort a vector of Shape subclasses by type, number of sides,
/// perimeter and area
class ShapeSorter
{
public:
    ///Constructor, reads in the vector of shapes
    ShapeSorter (std::vector<std::reference_wrapper<Shape> >& v);

    ///Prints shape matching the chosen type
    void types(const std::string& type);

    ///Prints shapes with a chosen number of sides
    void sides(const int& numSides);

    ///Prints all shapes in order of decreasing area
    void area();

    ///Prints all shapes in order of decreasing perimeter
    void perim();

private:
    //The vector of shapes
    const std::vector<std::reference_wrapper< Shape>> shapes;

    ///Prints the sorted shapes in order
    void printRank(std::multimap<double, std::reference_wrapper<Shape>> &rank);

    ///Prints the shapes matching the chosen criterium
    void printSort(std::vector<std::reference_wrapper<Shape>> &sorted);
};

#endif // SHAPESORTER_H_
