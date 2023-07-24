#include "ShapeSorter.h"

ShapeSorter::ShapeSorter(vector<shared_ptr<Shape>> shapes) {
	_shapes = shapes;
}

void ShapeSorter::OfType(string type) {
	for (const auto& s:_shapes)
	{
		if (s->Type() == type)
			cout << s->Str() << endl;
	}
}

void ShapeSorter::WithSides(int numberOfSides) {
	int matchingShapes = 0;
	for (const auto& s:_shapes)
	{
		if (s->Sides() == numberOfSides) {
			cout << s->Str() << endl;
			matchingShapes++;
		}
	}
	if (matchingShapes == 0)
		cout << printf("No shapes with %i sides", numberOfSides) << endl;
}

void ShapeSorter::AreaDescending() {
	auto sortedVector = copyPointers();
	sort(sortedVector.begin(), sortedVector.end(), [](shared_ptr<Shape> a, shared_ptr<Shape> b) { return a->Area() > b->Area(); });
	for (const auto& s : sortedVector)
		cout << s->Str() << endl;
}

void ShapeSorter::PerimeterDescending() {
	auto sortedVector = copyPointers();
	sort(sortedVector.begin(), sortedVector.end(), [](shared_ptr<Shape> a, shared_ptr<Shape> b) { return a->Perimeter() > b->Perimeter(); });
	for (const auto& s : sortedVector)
		cout << s->Str() << endl;
}

vector<shared_ptr<Shape>> ShapeSorter::copyPointers() {
	vector<shared_ptr<Shape>> newVector;
	for (const auto& s : _shapes)
		newVector.push_back(shared_ptr<Shape>(s));
	return newVector;
}
