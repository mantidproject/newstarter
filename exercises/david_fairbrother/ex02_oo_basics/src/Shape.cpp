
#include "Shape.h"

#include <string>

using namespace std;

struct Shape::ShapeImpl {
	ShapeImpl(string name, int sides) : shapeName(name), noOfSides(sides) {}
	string shapeName;
	int noOfSides;
};


Shape::Shape(std::string name, int sides) : ShapeData(new ShapeImpl(name, sides)) {};

Shape::~Shape() {
	delete ShapeData;
	ShapeData = nullptr;
}
