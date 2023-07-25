#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Shapes.h"
using namespace std;

class ShapeSorter {
public:
	ShapeSorter(vector<shared_ptr<Shape>> shapes);
	void OfType(string type);
	void WithSides(int numberOfSides);
	void AreaDescending();
	void PerimeterDescending();
private:
	vector<shared_ptr<Shape>> copyPointers();
	vector<shared_ptr<Shape>> _shapes;
};