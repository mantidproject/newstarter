#include "ShapeSorter.h"

//returns true iff the first shape has a greater area than the second
bool ShapeSorter::compare_area(const Shape* const s1, const Shape * const s2)
{
	return s1->area() > s2->area();
	
}

//returns true iff the first shape has a greater perimeter than the second
bool ShapeSorter::compare_perimeter(const Shape* const s1, const Shape* const s2)
{
	return s1->perimeter() > s2->perimeter();
}

//prints all the shapes of a chosen type
void ShapeSorter::print_type(std::ostream &out, const std::vector<Shape*> &all, const std::string &type) const
{
	for (const auto &all_shapes : all)
	{
		if (all_shapes->type() == type)
		{
			all_shapes->print_details(out);
		}
	}
}

//prints all the shapes of with a chosen number of sides
void ShapeSorter::print_sides(std::ostream &out, const std::vector<Shape*> &all, const int &sides) const
{
	for (const auto &all_shapes : all)
	{
		if (all_shapes->sides() == sides)
		{
			all_shapes->print_details(out);
		}
	}
}

//prints all the shapes in order of area descending
void ShapeSorter::print_area_descending(std::ostream &out, std::vector<Shape*> &all) const
{
	std::sort(all.begin(), all.end(), compare_area);
	for (const auto &all_shapes : all)
	{
		all_shapes->print_details(out);
	}
}

//prints all the shapes in order of area descending
void ShapeSorter::print_perimeter_descending(std::ostream &out, std::vector<Shape*> &all) const
{
	std::sort(all.begin(), all.end(), compare_perimeter);
	for (const auto &all_shapes : all)
	{
		all_shapes->print_details(out);
	}
}
