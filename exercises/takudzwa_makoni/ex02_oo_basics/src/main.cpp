


#include <iostream>
#include <math.h>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "isoTriangle.h"
#include "circle.h"
#include "shapeSorter.h"





int main() {
	
	square sqr(2); circle cir(3); rectangle rec(4,5); isoTriangle tri(2,3);
	std::vector< shape* > shapeVector({ &sqr, &cir, &rec, &tri }); // unique pointer?? 
	shapeSorter polysort(shapeVector);

	polysort.printOrderForPerim();
	polysort.printOrderForArea();
	polysort.printMatchForSide(3);
	polysort.printMatchForType("triangle");
	std::cin.get();

	return 0;
}

