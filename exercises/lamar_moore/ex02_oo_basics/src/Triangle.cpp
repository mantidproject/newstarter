#include "Triangle.h"
#include <cmath>

using namespace std;

namespace Shapes
{
	/** Constructor for Rectangle object
	@param base Length of the base of the isosceles triangle
	@param height Height of the isosceles triangle
	*/
	Triangle::Triangle(double base, double height): m_base(base), m_height(height)
	{
	}

	Triangle::~Triangle()
	{
	}

	const double Triangle::calculateArea()
	{
		return ( (m_base * m_height) / 2 );
	}

	const double Triangle::calculatePerimeter()
	{
		return ( m_base + (2 * sqrt( pow(m_height, 2) + (pow(m_base, 2) / 4 ) ) ) );
	}

	const string Triangle::getType()
	{
		return "Triangle";
	}

	const int Triangle::getNumSides()
	{
		return 3;
	}

};