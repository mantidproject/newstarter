#ifndef SHAPESORTER_H_
#define SHAPESORTER_H_

#include "Shape.h"
#include <vector>
#include <fstream>
#include <algorithm>

class ShapeSorter {
public:
	static bool compare_area(const Shape* const s1, const Shape* const s2);
	static bool compare_perimeter(const Shape* const s1, const Shape* const s2);
	void print_type(std::ostream &out, const std::vector<Shape*> &all, const std::string &type) const;
	void print_sides(std::ostream &out, const std::vector<Shape*> &all, const int &sides) const;
	void print_area_descending(std::ostream &out, std::vector<Shape*> &all) const;
	void print_perimeter_descending(std::ostream &out, std::vector<Shape*> &all) const;
};

#endif //SHAPESORTER_H_