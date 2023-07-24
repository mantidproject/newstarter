#include <math.h>
#include <typeinfo>
#include <vector>
#include "Shapes.h"
#include "ShapeSorter.h"
using namespace std;

int main(int, char**)
{
	auto a = Square(2);
	vector<Shape*> shapes = { &a, &Square(2), &Square(2.5), &Rectangle(1, 2), &Rectangle(2, 1), &Triangle(2, 3), &Triangle(3.1, 2.3), &Circle(4.1) };
	
	auto sorter = ShapeSorter(shapes);
	sorter.OfType(shapes[0]->Type());
};