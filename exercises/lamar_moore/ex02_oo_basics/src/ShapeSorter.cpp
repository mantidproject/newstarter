#include <iostream>
#include <algorithm>
#include <memory>
#include "ShapeSorter.h"


using namespace std;

namespace
{
	using namespace Shapes;

	/** Functor which is used to compare shape types with a matching value in std::remove_if
	*/
	class MatchTypeFunctor
	{
		string type;
	public:
		MatchTypeFunctor(string t): type(t)
		{
		}

		bool operator()(const shared_ptr<Shape> &shape) const 
		{
			bool isMatch = false;

			if(shape->getType().compare(type) == 0)
				isMatch = true;

			return isMatch;
		}
	};

	/** Functor which is used to compare shape types with a matching value in std::remove_if
	*/
	class MatchSideFunctor
	{
		int numSides;
	public:
		MatchSideFunctor(int sides): numSides(sides)
		{
		}

		bool operator()(const shared_ptr<Shape> &shape) const 
		{
			bool isMatch = false;

			if(shape->getNumSides() == numSides)
				isMatch = true;

			return isMatch;
		}
	};

	/** Functor which compares the magnitude of the areas between two Shapes
	*/
	class AreaFunctor
	{
	public:
		bool operator() (const shared_ptr<Shape> &first, const shared_ptr<Shape>& second)
		{
			return first->calculateArea() < second->calculateArea();
		}
	};

	/** Functor which compares the magnitude of the perimeter between two shapes
	*/
	class PerimeterFunctor
	{
	public:
		bool operator() (const shared_ptr<Shape> &first, const shared_ptr<Shape> &second)
		{
			return first->calculatePerimeter() < second->calculatePerimeter();
		}
	};
};

namespace Shapes
{
	/** Constructor
	*/
	ShapeSorter::ShapeSorter()
	{
	}

	/** Destructor
	*/
	ShapeSorter::~ShapeSorter()
	{
	}

	/** Prints all shapes which have the matching type specified by the first argument

	@param type Shape type for comparison with list of shapes
	@param shapes List of shapes for which types will be selectively printed
	*/
	void ShapeSorter::printByType(string type, vector<shared_ptr<Shape>> &shapes)
	{
		vector<shared_ptr<Shape>> copy;

		copy_if(shapes.begin(), shapes.end(), back_inserter(copy), MatchTypeFunctor(type));

		for_each(copy.begin(), copy.end(), printShape);
	}

	/** Prints all shapes which have the matching number of sides specified by the first argument

	@param sides Number of sides for comparison with list of shapes
	@param shapes List of shapes for which the number of sides will be selectively printed
	*/
	void ShapeSorter::printBySides(int numSides, vector<shared_ptr<Shape>> &shapes)
	{
		vector<shared_ptr<Shape>> copy;

		copy_if(shapes.begin(), shapes.end(), back_inserter(copy), MatchSideFunctor(numSides));

		for_each(copy.begin(), copy.end(), printShape);
	}

	/** Prints all shapes in order of area (descending)

	@param shapes List of shapes for which types will be printed in order 
	*/
	void ShapeSorter::printOrderArea(vector<shared_ptr<Shape>> &shapes)
	{
		vector<shared_ptr<Shape>> copy = shapes;

		sort(copy.begin(), copy.end(), AreaFunctor());

		for_each(copy.rbegin(), copy.rend(), printShape);
	}

	/** Prints all shapes in order of perimeter (descending)

	@param shapes List of shapes for which types will be printed in order 
	*/
	void ShapeSorter::printOrderPerimeter(vector<shared_ptr<Shape>> &shapes)
	{
		vector<shared_ptr<Shape>> copy = shapes;

		sort(copy.begin(), copy.end(), PerimeterFunctor());

		for_each(copy.rbegin(), copy.rend(), printShape);
	}


	/** Prints the shape properties to the console.

	The type, number of sides, perimeter and area are printed on a single line.

	@param shape Shape whose properties are printed to screen.
	*/
	void ShapeSorter::printShape(const shared_ptr<Shape> &shape)
	{
		cout << "Shape: " << shape->getType();
		cout << " Number of Sides: " << shape->getNumSides();
		cout << " Perimeter: " << shape->calculatePerimeter();
		cout << " Area: " << shape->calculateArea()<<endl;
	}
};
