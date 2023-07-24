#include "ShapeSorter.h"

ShapeSorter::ShapeSorter(vector<shared_ptr<Shape>> shapes) {
	_shapes = shapes;
}

void ShapeSorter::OfType(string type) {
	for (const auto& s:_shapes)
	{
		if (s->Type() == type)
			cout << s->Str() + "\n";
	}
}

void ShapeSorter::WithSides(int numberOfSides) {
	int matchingShapes = 0;
	for (const auto& s:_shapes)
	{
		if (s->Sides() == numberOfSides) {
			cout << s->Str() + "\n";
			matchingShapes++;
		}
	}
	if (matchingShapes == 0)
		cout << printf("No shapes with %i sides", numberOfSides);
}

void ShapeSorter::AreaDescending() {

}

void ShapeSorter::PerimeterDescending() {

}
