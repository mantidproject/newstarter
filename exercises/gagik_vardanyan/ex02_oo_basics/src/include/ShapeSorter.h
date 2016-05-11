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
    ShapeSorter();
    ShapeSorter(std::vector<Shape> & sh) : shapes(sh) {}
    void SortByArea() { sort(this->shapes.begin(),this->shapes.end(),Shape::CompareArea); }
    void SortByPerimeter() { sort(this->shapes.begin(),this->shapes.end(),Shape::ComparePerimeter);}
    void SelectByType(const std::string & type)
    {
        for(std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            if(it->GetType() != type) {shapes.erase(it);--it;}
        }
    }
    void SelectByNSides(const int & ns)
    {
        for(std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            if(it->GetNSides() != ns) {shapes.erase(it);--it;}
        }
    }
    void Print(std::ostream& out) const
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
