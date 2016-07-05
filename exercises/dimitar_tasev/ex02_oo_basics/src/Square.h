#ifndef SQUARE_SHAPE_H
#define SQUARE_SHAPE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <string>
#include "Shape.h"

//----------------------------------------------------------------------
// Forward declarations
//----------------------------------------------------------------------


class Square : public Shape{
public:
	Square(float side): m_sideCount(4), m_side(side), m_type("square")
	{
	};

	~Square() override
	{
	};

	/// Returns the side of the Square
	virtual int getSides() const override;

	// Returns the type 
	virtual std::string getType() const override;

	// Returns the volume (area) 
	virtual float getVolume() const override;

	// Returns the perimeter
	virtual float getPerimeter() const override;

private:
	int m_sideCount;
	float m_side;
	std::string m_type;

};

#endif /* SQUARE_SHAPE_H */
