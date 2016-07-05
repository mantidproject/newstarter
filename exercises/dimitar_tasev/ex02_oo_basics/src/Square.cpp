#include "Square.h"

/** Returns the number of sides of the shape
 *	@return int The number of sides
 */
int Square::getSides() const
{
	return m_sideCount;
}

/** Returns the type of the shape
*	@return std::string The type of the shape returned as a std::string
*/
std::string Square::getType() const
{
	return m_type;
}

/** Returns the volume(area) of the shape
*	@return int The volume(area) is returned as an int
*/
float Square::getVolume() const
{
	return m_side * m_side;
}

/** Returns the perimeter of the shape
*	@return int The parameter is returned as an int
*/
float Square::getPerimeter() const
{
	return m_side * 4;
}
