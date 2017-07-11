#include "Rectangle.h"
#include <ostream>

Rectangle::Rectangle(double Width, double Height)
    : m_Width(Width), m_Height(Height) {}

ShapeType Rectangle::getShapeType() const { return ShapeType::Rectangle; }

int Rectangle::getSideCount() const { return 4; }

double Rectangle::getPerimeter() const {
  return (getWidth() + getHeight()) * 2;
}

double Rectangle::getArea() const { return getWidth() * getHeight(); }

void Rectangle::printAttributes(std::ostream &OutputStream) const {
  OutputStream << "Width: " << getWidth() << ", Height: " << getHeight();
}

double Rectangle::getWidth() const { return m_Width; }

double Rectangle::getHeight() const { return m_Height; }
