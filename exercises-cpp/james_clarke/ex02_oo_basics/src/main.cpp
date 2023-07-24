#include <math.h>
#include <typeinfo>
#include <vector>
#include "Shapes.h"
#include "ShapeSorter.h"
using namespace std;

int main(int, char**)
{
	vector<shared_ptr<Shape>> shapes;
	shapes.push_back(make_shared<Square>(2));
	shapes.push_back(make_shared<Square>(2.5));
	shapes.push_back(make_shared<Rectangle>(1, 2));
	shapes.push_back(make_shared<Rectangle>(2, 1));
	shapes.push_back(make_shared<Triangle>(2, 3));
	shapes.push_back(make_shared<Triangle>(3.1, 2.3));
	shapes.push_back(make_shared<Circle>(4.1));

	auto sorter = ShapeSorter(shapes);
	sorter.OfType(shapes[0]->Type());
	cout << endl;
	sorter.WithSides(4);
	cout << endl;
	sorter.WithSides(6);
	cout << endl;
	cout << "Area descending:" << endl;
	sorter.AreaDescending();
	cout << endl;
	cout << "Perimeter descending:" << endl;
	sorter.PerimeterDescending();
};