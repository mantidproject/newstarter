#include "Circle.h"

/** Returns the number of sides of the shape
*	@return int The number of sides
*/
int Circle::getSides() const
{
	return m_sideCount;
}

/** Returns the type of the shape
*	@return std::string The type of the shape returned as a std::string
*/
std::string Circle::getType() const
{
	return m_type;
}

/** Returns the volume(area) of the shape
*	@return int The volume(area) is returned as an int
*/
float Circle::getVolume() const
{
	return M_PI * m_radius * m_radius;
}

/** Returns the perimeter of the shape
*	@return int The parameter is returned as an int
*/
float Circle::getPerimeter() const
{
	return 2 * M_PI * m_radius;
}