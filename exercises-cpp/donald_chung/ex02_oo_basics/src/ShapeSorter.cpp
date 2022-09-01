#include "ShapeSorter.h"
#include <vector>
#include <algorithm>

ShapeSorter::ShapeSorter() {};

bool bool_byarea_dec(Shape *a, Shape *b) 
{
	return a->area() > b->area();
}
void ShapeSorter::print_byarea_dec(std::vector<Shape*> shapes)
{
	std::sort(shapes.begin(), shapes.end(), bool_byarea_dec);
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->print();
	}
}

bool bool_byperimeter_dec(Shape* a, Shape* b) 
{
	return a->perimeter() > b->perimeter();
}

void ShapeSorter::print_byperimeter_dec(std::vector<Shape*> shapes)
{
	std::sort(shapes.begin(), shapes.end(), bool_byperimeter_dec);
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->print();
	}
}

void ShapeSorter::print_type(std::vector<Shape*> shapes, std::string type)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->get_type() == type)
		{
			shapes[i]->print();
		}
	}
}

void ShapeSorter::print_sides(std::vector<Shape*> shapes, int sides)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->get_num_sides() == sides)
		{
			shapes[i]->print();
		}
	}
}
