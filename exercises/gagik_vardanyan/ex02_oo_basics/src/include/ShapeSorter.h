/*!
* A class that stores vector of shapes and sorts/selects by criteria
*/

#ifndef CLASS_SHAPESORTER
#define CLASS_SHAPESORTER
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"

class ShapeSorter {
private:
    std::vector<const Shape*> & shapes; /**< vector of shape pointers */
public:
    ///default constructor
    ShapeSorter();

    ///constructor from vector
    /// @param sh vector of shapes
    ShapeSorter(std::vector<const Shape*> & sh) : shapes(sh) {}

    ///sorts by area, prints
    /// @param out ostream to print the output to
    void PrintSortByArea(std::ostream& out)
    {
        sort(shapes.begin(),shapes.end(),Shape::CompareArea);
        PrintAll(out);
    }

    ///sorts by perimeter, prints
    /// @param out ostream to print the output to
    void PrintSortByPerimeter(std::ostream& out)
    {
        sort(shapes.begin(),shapes.end(),Shape::ComparePerimeter);
        PrintAll(out);
    }

    ///prints the shapes of the given type
    /// @param out ostream to print the output to
    /// @param type the type of the shapes to print
    void PrintSelectByType(std::ostream& out, const std::string & type) const;

    ///prints the shapes with given number of sides
    /// @param out ostream to print the output to
    /// @param ns the number of sides of the shapes to print
    void PrintSelectByNSides(std::ostream& out, const int & ns) const;

    ///prints out all the shapes to the stream
    /// @param out ostream to print the output to
    void PrintAll(std::ostream& out) const;
};

#endif
