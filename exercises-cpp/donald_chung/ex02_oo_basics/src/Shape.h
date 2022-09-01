#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
protected:
    std::string my_type;
    int num_sides;
public:
    Shape(std::string my_type_i, int num_sides_i);
    virtual double perimeter() = 0;
    virtual double area() = 0;
    int get_num_sides();
    std::string get_type();
    virtual void print() = 0;
};

#endif