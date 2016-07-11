#include "Triangle.h"

/** Returns the number of sides of the shape
*	@return int The number of sides
*/
int Triangle::getSides() const
{
	return m_sideCount;
}

/** Returns the type of the shape
*	@return std::string The type of the shape returned as a std::string
*/
std::string Triangle::getType() const
{
	return m_type;
}

/** Returns the volume(area) of the shape
*	@return int The volume(area) is returned as an int
*/
float Triangle::getVolume() const
{
	// Has the same result, should be faster because it doesn't have division
	return m_base + sqrt(m_base * m_base + 4 * m_height * m_height);
	//return m_base + 2 * (sqrt(m_height*m_height + ((m_base*m_base) / 4)));
}

/** Returns the perimeter of the shape
*	@return int The parameter is returned as an int
*/
float Triangle::getPerimeter() const
{
	return (m_base * m_height) / 2;
}