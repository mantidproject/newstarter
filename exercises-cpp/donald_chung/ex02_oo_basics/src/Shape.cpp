#include "Shape.h"

Shape::Shape(std::string my_type_i, int num_sides_i) : my_type{ my_type_i }, num_sides{ num_sides_i } {
}

int Shape::get_num_sides()
{
    return num_sides;
}
std::string Shape::get_type()
{
    return my_type;
}
