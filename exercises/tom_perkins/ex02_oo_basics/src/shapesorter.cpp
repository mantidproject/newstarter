#include "shapesorter.h"

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * \brief Constructs a new ShapeSorter using the given stream as its output
 *
 * \param stream Stream to write output of filter operations to
 */
ShapeSorter::ShapeSorter(std::ostream& stream) : m_stream(stream) { }

/**
 * \brief Selects all shapes in the given vector that have the given type
 *
 * \param shapes Vector of shared_ptr's to Shape objects, to select from
 * \param type Shape type to match
 */
void ShapeSorter::selectByType(const std::vector<std::shared_ptr<Shape> >& shapes, const std::string& type) const
{
	m_stream << "Shapes of type " << type << " are:" << std::endl;
	for (auto iter = shapes.begin(); iter != shapes.end(); iter++)
	{
		if ((*iter)->type == type)
		{
			m_stream << (*iter)->name << std::endl;
		}
	}

}
