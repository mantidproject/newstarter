#ifndef SHAPE_H_
#define SHAPE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------
#include <string>

/**
	Abstract base class for all shapes.

	Provides common interface for all shapes.
	
	Declares m_type and m_sideCount members that must be
	supported by all Shapes. 
*/
class Shape
{
public:
	/// Constructor
	Shape(std::string type, int sidecount);
	
	/// Destructor
	virtual ~Shape();

	/// Calculate shape perimeter
	virtual double calcPerimeter() = 0;

	/// Calculate shape area
	virtual double calcArea() = 0;

	/// Get type of shape
	virtual std::string getType() const { return m_type; }

	/// Get the number of sides this shape has
	virtual int getSideCount() const { return m_sideCount; }

private:
	/// String that represents the type of this shape
	std::string m_type;

	/// Number of sides that this shape has
	int	m_sideCount;
};

#endif // SHAPE_H_
