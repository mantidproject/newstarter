#pragma once
#include "Shape.h"
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class ShapeSorter
{
public:
	ShapeSorter();
	void matchType(string type, vector<Shape*> shapes);
	void matchSides(int sides, vector<Shape*> shapes);
	void sortArea(vector<Shape*> shapes);
	void sortPerimeter(vector<Shape*> shapes);
	void printShapes(vector<Shape*> &shapes);
	~ShapeSorter();
	vector<Shape> shapes;
};

bool compareArea(const Shape* x, const Shape* y);
bool comparePerimeter(const Shape* x, const Shape* y);


