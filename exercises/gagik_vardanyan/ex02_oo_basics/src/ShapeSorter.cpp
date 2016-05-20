#include "include/ShapeSorter.h"

///prints the shapes of the given type
/// @param out ostream to print the output to
/// @param type the type of the shapes to print
void ShapeSorter::PrintSelectByType(std::ostream& out, const std::string & type) const
{
    out << "Type\tArea\tPerimeter\n";
    for(std::vector<const Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
    {
        if((*it)->GetType() == type)
        {
            out << (*it)->GetType() << "\t" << (*it)->ComputeArea() << "\t"
                << (*it)->ComputePerimeter() << std::endl;
        }
    }
}

///prints the shapes with given number of sides
/// @param out ostream to print the output to
/// @param ns the number of sides of the shapes to print
void ShapeSorter::PrintSelectByNSides(std::ostream& out, const int & ns) const
{
    out << "Type\tArea\tPerimeter\n";
    for(std::vector<const Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
    {
        if((*it)->GetNSides() == ns)
        {
            out << (*it)->GetType() << "\t" << (*it)->ComputeArea() << "\t"
                << (*it)->ComputePerimeter() << std::endl;
        }
    }
}

///prints out all the shapes to the stream
/// @param out ostream to print the output to
void ShapeSorter::PrintAll(std::ostream& out) const
{
    out << "Type\tArea\tPerimeter\n";
    for(std::vector<const Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
    {
        out << (*it)->GetType() << "\t" << (*it)->ComputeArea() << "\t"
            << (*it)->ComputePerimeter() << std::endl;
    }
}
