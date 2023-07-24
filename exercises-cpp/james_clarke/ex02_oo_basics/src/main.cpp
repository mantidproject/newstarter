#include <math.h>
#include <typeinfo>
#include <vector>
#include "Shapes.h"
#include "ShapeSorter.h"
using namespace std;

int main(int, char**)
{
	auto sq1 = make_shared<Square>(2);
	auto sh1 = static_pointer_cast<Shape>(sq1);
	auto sq2 = make_shared<Square>(2.5);
	auto sh2 = static_pointer_cast<Shape>(sq2);
	auto re1 = make_shared<Rectangle>(1, 2);
	auto sh3 = static_pointer_cast<Shape>(re1);
	auto re2 = make_shared<Rectangle>(2, 1);
	auto sh4 = static_pointer_cast<Shape>(re2);
	auto tr1 = make_shared<Triangle>(2, 3);
	auto sh5 = static_pointer_cast<Shape>(tr1);
	auto tr2 = make_shared<Triangle>(3.1, 2.3);
	auto sh6 = static_pointer_cast<Shape>(tr2);
	auto ci1 = make_shared<Circle>(4.1);
	auto sh7 = static_pointer_cast<Shape>(ci1);

	vector<shared_ptr<Shape>> shapes = { sh1, sh2,  sh3, sh4, sh5, sh6, sh7 };

	auto sorter = ShapeSorter(shapes);
	sorter.OfType(shapes[0]->Type());
	cout << '\n';
	sorter.WithSides(4);
	cout << '\n';
	sorter.WithSides(6);
	cout << '\n';
};