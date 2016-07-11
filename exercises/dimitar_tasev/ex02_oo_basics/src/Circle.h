#ifndef CIRCLE_SHAPE_H
#define CIRCLE_SHAPE_H

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <string>
#include <math.h> // In header or cpp file? only used in cpp
#include "Shape.h"

class Circle : public Shape{
public:
	Circle(float radius) : m_sideCount(0), m_radius(radius), m_type("circle")
	{
	}

	~Circle() override
	{
	}

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
	float m_radius;
	std::string m_type;
};

#endif /* CIRCLE_SHAPE_H */ 
