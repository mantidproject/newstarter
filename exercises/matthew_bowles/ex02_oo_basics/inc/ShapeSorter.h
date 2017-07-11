#pragma once
#include "Shape.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ShapeSorter
{
public:
	ShapeSorter();
	~ShapeSorter();
	void matchType(const string& type, vector<Shape*> shapes);
	void matchSides(int sides, vector<Shape*> shapes);
	void sortArea(vector<Shape*>& shapes);
	void sortPerimeter(vector<Shape*>& shapes);

private:
	void printShapes(const vector<Shape*> &shapes);
	vector<Shape> shapes;
};

bool compareArea(const Shape* x, const Shape* y);
bool comparePerimeter(const Shape* x, const Shape* y);


