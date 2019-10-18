#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shapes.h"

namespace {
	constexpr double PI = 3.141592653589793238463;
}
/**
 * This class contains an abstraction of a Circle
 */
class Circle : public BaseShape
{
public:
	static const std::string SHAPENAME;
	static const int NUMSIDES;
	// Constructors
	Circle();
	Circle(const double radius);
	// Getters
	int getNumSides() const override;
	std::string getShapeName() const override;
	// Print shape information
	void printShapeDimensions() const override;
private:
	// Radius
	double m_radius;
	// Private method to calculate area
	double calculateArea()
	{
		return PI * m_radius * m_radius;
	}
	// Private method to calculate perimeter
	double calculatePerimeter()
	{
		return 2 * PI * m_radius;
	}
};





















#endif