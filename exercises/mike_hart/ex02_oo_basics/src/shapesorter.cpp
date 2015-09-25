#include "shape.h"



/**
 * Constructs shape.
 *
 * @param type String that represents the type of this shape
 * @param sidecount How many sides a shape of this type has
 */
Shape::Shape(std::string type, int sidecount)
	: m_type(type)
	, m_sideCount(sidecount)
{
	// Empty by design
}

/**
 * Destroys shape.
 *
 * Virtual to ensure derived types are destroyed correctly when
 * deleted via base class pointer.
 */
Shape::~Shape()
{
	// Empty by design
}
