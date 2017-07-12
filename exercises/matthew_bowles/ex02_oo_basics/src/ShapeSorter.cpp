#include "ShapeSorter.h"


/** prints shapes that match a given type
*
* @param type The type of shape to find e.g. "Square"
* @param shapes The vector of shape pointers to traverse
*
*/
void ShapeSorter::matchType(const string& type, const vector<Shape*>& shapes)
{
	vector<Shape*> matches;
	for (auto s : shapes)
	{
		if (s->getType() == type)
		{
			matches.push_back(s);
		}
	}
	printShapes(matches);
}

/** prints shapes with a given number of sides
*
* @param type The number of sides to search for
* @param shapes The vector of shape pointers to traverse
*
*/
void ShapeSorter::matchSides(int sides, const vector<Shape*>& shapes)
{
	vector<Shape*> matches;
	for (auto s : shapes)
	{
		if (s->getSideCount() == sides)
		{
			matches.push_back(s);
		}
	}
	printShapes(matches);
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
bool ShapeSorter::compareArea(const Shape* x, const Shape* y)
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
bool ShapeSorter::comparePerimeter(const Shape* x, const Shape* y)
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
	for (auto s : shapes)
		s->print();
	cout << '\n';
}


