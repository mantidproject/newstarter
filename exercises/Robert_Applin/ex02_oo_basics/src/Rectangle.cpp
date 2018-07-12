#include "Rectangle.h"

Rectangle::Rectangle(double width, double height)
    : m_width(width), m_height(height), m_area(width * height),
      m_perimeter(width * 2 + height * 2) {}

double Rectangle::getWidth() const { return m_width; }

double Rectangle::getHeight() const { return m_height; }

std::string Rectangle::getType() const { return "rectangle"; }

std::size_t Rectangle::getNumberOfEdges() const { return 4; }

double Rectangle::getPerimeter() const { return m_perimeter; }

double Rectangle::getArea() const { return m_area; }
