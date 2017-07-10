#pragma once
#include "Shape.h"
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class ShapeSorter
{
public:
	ShapeSorter();
	void matchType(string type, vector<Shape*> shapes);
	void printShapes(vector<Shape*> &shapes);
	~ShapeSorter();
	vector<Shape> shapes;
};

