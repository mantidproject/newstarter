#ifndef RECTANGLE_SHAPE_H_
#define RECTANGLE_SHAPE_H_

//----------------------------------------------------------------------
// Includes
//----------------------------------------------------------------------

#include <string>
#include "Shape.h"


class Rectangle : public Shape{
public:
	Rectangle(float side1, float side2): m_sideCount(4), m_side1(side1), m_side2(side2), m_type("rectangle")
	{
	}

	~Rectangle()
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
	float m_side1;
	float m_side2;
	std::string m_type;

};

#endif /* RECTANGLE_SHAPE_H_*/
