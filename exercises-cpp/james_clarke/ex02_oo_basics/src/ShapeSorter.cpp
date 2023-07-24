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

void ShapeSorter::WithSides() {

}

void ShapeSorter::AreaDescending() {

}

void ShapeSorter::PerimeterDescending() {

}
