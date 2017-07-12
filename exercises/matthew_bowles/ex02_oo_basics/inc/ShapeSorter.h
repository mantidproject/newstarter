#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "Shape.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ShapeSorter
{
public:
	void matchType(const string& type, const vector<Shape*>& shapes);
	void matchSides(int sides, const vector<Shape*>& shapes);
	void sortArea(vector<Shape*>& shapes);
	void sortPerimeter(vector<Shape*>& shapes);

private:
	void printShapes(const vector<Shape*> &shapes);
	static bool compareArea(const Shape* x, const Shape* y);
	static bool comparePerimeter(const Shape* x, const Shape* y);
};

#endif
