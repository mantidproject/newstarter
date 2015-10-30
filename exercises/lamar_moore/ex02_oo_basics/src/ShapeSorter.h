/** ShapeSorter.h "ShapeSorter.h"

	The ShapeSorter class contains a group of utility methods which allow users to manipulate the display (printing) of a list of shapes.
	These utilities includes printing only shapes of a particular type, or number of sided and printing shapes in order of area and perimeter.
*/

#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "Shape.h"
#include <vector>
#include <memory>

using namespace std;

namespace Shapes
{
	class ShapeSorter
	{
	public:
		ShapeSorter();
		~ShapeSorter();

		void printByType(ShapeType type, vector<shared_ptr<Shape>> &shapes);
		void printBySides(int numSides, vector<shared_ptr<Shape>> &shapes);
		void printOrderArea(vector<shared_ptr<Shape>> &shapes);
		void printOrderPerimeter(vector<shared_ptr<Shape>> &shapes);

	private:
		static void ShapeSorter::printShape(shared_ptr<Shape> shape);

	};
};

#endif