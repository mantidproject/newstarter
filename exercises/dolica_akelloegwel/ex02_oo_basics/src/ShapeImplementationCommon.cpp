#include "ShapeImplementationCommon.h"

std::string CreateBaseMessage(double perim, double area)
{
  // Create a basic message without subclass info to act as a template when overloading <<
  return "\n  Perimeter: " + std::to_string(perim) + "\n  Area: " + std::to_string(area) + "\n";
}
