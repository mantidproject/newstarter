#include "ShapeSorter.h"

bool ShapeSorter::AreaComparator(const std::unique_ptr<Shape> &s1, const std::unique_ptr<Shape> &s2)
{
	return s2->GetArea() < s1->GetArea() || (s1->GetArea() >= s2->GetArea() && s1->GetArea() < s2->GetArea());
}
bool ShapeSorter::PerimeterComparator(const std::unique_ptr<Shape> &s1, const std::unique_ptr<Shape> &s2)
{
	return s2->GetPerimeter() < s1->GetPerimeter() || (s1->GetPerimeter() >= s2->GetPerimeter() && s1->GetPerimeter() < s2->GetPerimeter());
}
void ShapeSorter::PrintBasedOnType(const std::vector<std::unique_ptr<Shape>> &shapes, std::string type) const
{
	// Print shapes that have a given type
	for (auto &shape : shapes)
		if (shape.get()->GetType() == type)
			std::cout << *shape.get() << std::endl;
}
void ShapeSorter::PrintBasedOnNSides(const std::vector<std::unique_ptr<Shape>> &shapes, int numSides) const
{
	// Print shapes that have a given number of sides
	for (auto &shape : shapes)
		if (shape.get()->GetNumSides() == numSides)
			std::cout << *shape.get() << std::endl;
}
std::vector<std::unique_ptr<Shape>> ShapeSorter::SortByAreaDesc(const std::vector<std::unique_ptr<Shape>> &shapes) const
{
	// Create a copy of the shapes vector
	std::vector<std::unique_ptr<Shape>> copyShapes;

	for (auto &shape : shapes)
     copyShapes.push_back(std::unique_ptr<Shape>(shape->clone()));

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), AreaComparator);

	return copyShapes;
}
std::vector<std::unique_ptr<Shape>> ShapeSorter::SortByPerimeterDesc(const std::vector<std::unique_ptr<Shape>> &shapes) const
{
	std::vector<std::unique_ptr<Shape>> copyShapes;

  for (auto &shape : shapes)
    copyShapes.push_back(std::unique_ptr<Shape>(shape->clone()));

	// Sort the copied vector
	std::sort(copyShapes.begin(), copyShapes.end(), PerimeterComparator);

	return copyShapes;
}
void ShapeSorter::PrintShapes(const std::vector<std::unique_ptr<Shape>> &shapes) const
{
	for (auto &shape : shapes)
		std::cout << *shape.get() << std::endl;
}
