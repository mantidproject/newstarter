#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Shapes.h"
using namespace std;

class ShapeSorter {
public:
	ShapeSorter(vector<Shape*> shapes);
	void OfType(string type);
	void WithSides();
	void AreaDescending();
	void PerimeterDescending();
private:
	vector<Shape*> _shapes;
};