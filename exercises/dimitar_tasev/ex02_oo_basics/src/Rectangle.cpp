#include "Rectangle.h"

/** Returns the number of sides of the shape
*	@return int The number of sides
*/
int Rectangle::getSides() const
{
	return m_sideCount;
}

/** Returns the type of the shape
*	@return std::string The type of the shape returned as a std::string
*/
std::string Rectangle::getType() const
{
	return m_type;
}

/** Returns the volume(area) of the shape
*	@return int The volume(area) is returned as an int
*/
float Rectangle::getVolume() const
{
	return m_side1 * m_side2;
}

/** Returns the perimeter of the shape
 *	@return int The parameter is returned as an int
 */
float Rectangle::getPerimeter() const
{
	return m_side1 * 2 + m_side2 * 2;
}
