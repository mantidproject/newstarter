#ifndef TRIANGLE_SHAPE_H_
#define TRIANGLE_SHAPE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <string>
#include <math.h>
#include "Shape.h"

class Triangle : public Shape{
public:
	Triangle(float height, float base): m_sideCount(3), m_height(height), m_base(base), m_type("triangle")
	{
	}

	~Triangle() override
	{
	}

	/// Returns the side of the Square
	virtual int getSides() const override;

	/// Returns the type 
	virtual std::string getType() const override;

	/// Returns the volume (area) 
	virtual float getVolume() const override;

	/// Returns the perimeter
	virtual float getPerimeter() const override;

private:
	int m_sideCount;
	float m_height;
	float m_base;
	std::string m_type;
};
#endif TRIANGLE_SHAPE_H_
