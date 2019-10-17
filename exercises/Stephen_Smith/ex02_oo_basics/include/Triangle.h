#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Shapes.h"
/**
 * This class contains an abstraction of a triangle
 */
class Triangle : public BaseShape
{
public:
	static const std::string SHAPENAME;
	static const int NUMSIDES;
	// Constructors
	Triangle();
	Triangle(const double base, const double height);
	// Getters
	int getNumSides() const override;
	std::string getShapeName() const override;
	// Print shape information
	void printShapeDimensions() const override;
private:
	// Triangle dimensions
	double m_base;
	double m_height;
	// Private method to calculate area
	double calculateArea()
	{
		return (1.00 / 2.00) * (m_base * m_height);
	}
	// Private method to calculate perimeter
	double calculatePerimeter()
	{
		return m_base + 2 * sqrt(m_height * m_height + 0.25 * m_base * m_base);
	}
};















#endif