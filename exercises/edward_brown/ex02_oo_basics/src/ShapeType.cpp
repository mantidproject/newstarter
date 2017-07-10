#include "ShapeType.h"
#include <cassert>
std::ostream& operator<<(std::ostream& OutputStream, ShapeType type) {
    switch(type) {
        case ShapeType::Square: 
            OutputStream << "Square";
            break;
        case ShapeType::Rectangle:
            OutputStream << "Rectangle";
            break;
        case ShapeType::Circle:
            OutputStream << "Circle";
            break;
        case ShapeType::Triangle:
            OutputStream << "Triangle";
            break;
        default:
            assert(false && "Attempted to print undefined ShapeType.");
    }
    return OutputStream;
}
