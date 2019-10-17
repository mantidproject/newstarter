#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shapes.h"
/**
 * This class contains an abstraction of a rectangle
 */
class Rectangle : public BaseShape
{
public:
	static const std::string SHAPENAME;
	static const int NUMSIDES;
	// Constructors
	Rectangle();
	Rectangle(const double width, const double depth);
	// Getters
	int getNumSides() const override;
	std::string getShapeName() const override;
	// Print shape information
	void printShapeDimensions() const override;
private:
	// Width
	double m_width;
	// Depth
	double m_depth;
	// Private method to calculate area
	double calculateArea()
	{
		return m_width * m_depth;
	}
	// Private method to calculate perimeter
	double calculatePerimeter()
	{
		return  m_width * 2 + m_depth * 2;
	}
};
#endif