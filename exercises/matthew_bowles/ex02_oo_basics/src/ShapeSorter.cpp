#include "ShapeSorter.h"

using namespace std;

ShapeSorter::ShapeSorter()
{
}

void ShapeSorter::matchType(string type, vector<Shape*> shapes)
{
	vector<Shape*>::iterator iter = shapes.begin();
	while (iter != shapes.end())
	{
		if (type.compare((*iter)->getType()) != 0)
			iter = shapes.erase(iter);
		else
			++iter;
	}
	printShapes(shapes);
}

void ShapeSorter::matchSides(int sides, vector<Shape*> shapes)
{
	vector<Shape*>::iterator iter = shapes.begin();
	while (iter != shapes.end())
	{
		if ((*iter)->sideCount != sides)
			iter = shapes.erase(iter);
		else
			++iter;
	}
	printShapes(shapes);
}

void ShapeSorter::sortArea(vector<Shape*> shapes)
{
	sort(shapes.begin(), shapes.end(), compareArea);
	printShapes(shapes);
}

bool compareArea(const Shape* x, const Shape* y)
{
	return x->calcArea() > y->calcArea();
}

void ShapeSorter::sortPerimeter(vector<Shape*> shapes)
{
	sort(shapes.begin(), shapes.end(), comparePerimeter);
	printShapes(shapes);
}

bool comparePerimeter(const Shape* x, const Shape* y)
{
	return x->calcPerimeter() > y->calcPerimeter();
}

void ShapeSorter::printShapes(vector<Shape*> &shapes)
{
	vector<Shape*>::const_iterator iter = shapes.begin();
	while (iter != shapes.end())
	{
		(*iter)->print();
		++iter;
	}
}

ShapeSorter::~ShapeSorter()
{
}

