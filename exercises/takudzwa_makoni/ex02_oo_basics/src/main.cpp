
//#include "pch.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "isoTriangle.h"
#include "circle.h"
#include "shapeSorter.h"


square s; circle c; rectangle r; isoTriangle t;
std::vector<shape*> shapeVector({ &s, &c, &r, &t });
shapeSorter polysort;


int main() {
	
	//set dimensions of shape objects
	s.sideLength = 3;
	r.sideHeight, r.sideWidth = 3,4;
	c.radius = 4;
	t.base, t.height = 2, 3;

	//set chosen values
	polysort.chosenNumOfSides = 3;
	polysort.chosenType = "triangle";

	//set vector of shapes to be sorted to shapeVector.
	polysort.shapes = shapeVector;

	polysort.printMatchForSide();
	polysort.printMatchForType();
	polysort.printOrderForArea();
	polysort.printOrderForPerim();

	std::cin.get();

	return 0;
}

