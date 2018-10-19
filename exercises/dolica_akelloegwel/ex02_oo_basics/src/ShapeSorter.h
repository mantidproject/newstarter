#pragma once

#include "Shape.h"
#include <memory>
#include <functional>

class ShapeSorter
{
public:
	static bool AreaComparator(const std::unique_ptr<Shape> &s1, const std::unique_ptr<Shape> &s2);
	static bool PerimeterComparator(const std::unique_ptr<Shape> &s1, const std::unique_ptr<Shape> &s2);
	void PrintBasedOnType(const std::vector<std::unique_ptr<Shape>> &shapes, std::string type) const;
	void PrintBasedOnNSides(const std::vector<std::unique_ptr<Shape>> &shapes, int numSides) const;
	std::vector<std::unique_ptr<Shape>> SortByAreaDesc(const std::vector<std::unique_ptr<Shape>> &shapes) const;
	std::vector<std::unique_ptr<Shape>> SortByPerimeterDesc(const std::vector<std::unique_ptr<Shape>> &shapes) const;
	void PrintShapes(const std::vector<std::unique_ptr<Shape>> &shapes) const;

};
