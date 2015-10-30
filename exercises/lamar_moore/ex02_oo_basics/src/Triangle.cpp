#include "Triangle.h"
#include <cmath>

using namespace std;

namespace Shapes
{
	/** Constructor for Rectangle object
	@param base Length of the base of the isosceles triangle
	@param height Height of the isosceles triangle
	*/
	Triangle::Triangle(double base, double height)
	{
		this->base = base;
		this->height = height;
		this->type = ShapeType::TRIANGLE;
		this->numSides = 3;
	}

	Triangle::~Triangle()
	{
	}

	double Triangle::calculateArea()
	{
		return ( (base * height) / 2 );
	}

	double Triangle::calculatePerimeter()
	{
		return ( base + (2 * sqrt( pow(height, 2) + (pow(base, 2) / 4 ) ) ) );
	}

};