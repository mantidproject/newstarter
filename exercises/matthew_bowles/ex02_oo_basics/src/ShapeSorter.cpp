#include "ShapeSorter.h"

ShapeSorter::ShapeSorter()
{
}

/** prints shapes that match a given type
*
* @param type The type of shape to find e.g. "Square"
* @param shapes The vector of shape pointers to traverse
*
*/
void ShapeSorter::matchType(const string& type, vector<Shape*> shapes)
{
	auto iter = shapes.begin();
	while (iter != shapes.end())
	{
		if (type.compare((*iter)->getType()) != 0)
			iter = shapes.erase(iter);
		else
			++iter;
	}
	printShapes(shapes);
}

/** prints shapes with a given number of sides
*
* @param type The number of sides to search for
* @param shapes The vector of shape pointers to traverse
*
*/
void ShapeSorter::matchSides(int sides, vector<Shape*> shapes)
{
	auto iter = shapes.begin();
	while (iter != shapes.end())
	{
		if ((*iter)->getSideCount() != sides)
			iter = shapes.erase(iter);
		else
			++iter;
	}
	printShapes(shapes);
}

/** sorts shapes by their area (descending)
*
* @param shapes The vector of shape pointers to sort
*
*/
void ShapeSorter::sortArea(vector<Shape*>& shapes)
{
	sort(shapes.begin(), shapes.end(), compareArea);
	printShapes(shapes);
}

/** compares the area of two shapes
*
* @param x Pointer to first shape to compare
* @param y Pointer to second shape to compare
*
*/
bool compareArea(const Shape* x, const Shape* y)
{
	return x->calcArea() > y->calcArea();
}

/** sorts shapes by their perimeter (descending)
*
* @param shapes The vector of shape pointers to sort
*
*/
void ShapeSorter::sortPerimeter(vector<Shape*>& shapes)
{
	sort(shapes.begin(), shapes.end(), comparePerimeter);
	printShapes(shapes);
}

/** compares the perimeter of two shapes
*
* @param x Pointer to first shape to compare
* @param y Pointer to second shape to compare
*
*/
bool comparePerimeter(const Shape* x, const Shape* y)
{
	return x->calcPerimeter() > y->calcPerimeter();
}

/** prints out a vector of shapes
*
* @param shapes The vector of shape pointers to print
*
*/
void ShapeSorter::printShapes(const vector<Shape*>& shapes)
{
	auto iter = shapes.cbegin();
	while (iter != shapes.cend())
	{
		(*iter)->print();
		++iter;
	}
	cout << endl;
}

ShapeSorter::~ShapeSorter()
{
}

