#pragma once

#include "Shape.h"
#include <vector>
#include <fstream>
#include <algorithm>

class ShapeSorter {
public:
	static bool compare_area(Shape* &s1,Shape* &s2);
	static bool compare_perimeter(Shape* &s1, Shape* &s2);
	void print_type(std::ostream &out, std::vector<Shape*> &all, std::string &type) const;
	void print_sides(std::ostream &out, std::vector<Shape*> &all, int &sides) const;
	void print_area_descending(std::ostream &out, std::vector<Shape*> &all) const;
	void print_perimeter_descending(std::ostream &out, std::vector<Shape*> &all) const;
};