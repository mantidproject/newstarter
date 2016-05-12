#ifndef CLASS_SHAPESORTER
#define CLASS_SHAPESORTER
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"

class ShapeSorter {
private:
    std::vector<Shape> & shapes;
public:
    //default constructor
    ShapeSorter();

    //constructor from vector
    ShapeSorter(std::vector<Shape> & sh) : shapes(sh) {}

    //sorts by area, prints
    void PrintSortByArea(std::ostream& out)
    {
        sort(shapes.begin(),shapes.end(),Shape::CompareArea);
        PrintAll(out);
    }

    //sorts by perimeter, prints
    void PrintSortByPerimeter(std::ostream& out)
    {
        sort(shapes.begin(),shapes.end(),Shape::ComparePerimeter);
        PrintAll(out);
    }

    //prints the shapes of the given type
    void PrintSelectByType(std::ostream& out, const std::string & type) const
    {
        out << "Type\tArea\tPerimeter\n";
        for(std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            if(it->GetType() == type)
            {
                out << it->GetType() << "\t" << it->ComputeArea() << "\t"
                    << it->ComputePerimeter() << std::endl;
            }
        }
    }

    //prints the shapes with given number of sides
    void PrintSelectByNSides(std::ostream& out, const int & ns) const
    {
        out << "Type\tArea\tPerimeter\n";
        for(std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            if(it->GetNSides() == ns)
            {
                out << it->GetType() << "\t" << it->ComputeArea() << "\t"
                    << it->ComputePerimeter() << std::endl;
            }
        }
    }

    //prints out all the shapes to the stream
    void PrintAll(std::ostream& out) const
    {
        out << "Type\tArea\tPerimeter\n";
        for(std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            out << it->GetType() << "\t" << it->ComputeArea() << "\t"
                << it->ComputePerimeter() << std::endl;
        }
    }
};

#endif
