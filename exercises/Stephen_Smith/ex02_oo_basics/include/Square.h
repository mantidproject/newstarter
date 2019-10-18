#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shapes.h"

/**
 * This class contains an abstraction of a square
 */
class Square : public BaseShape
{
public:
	static const std::string SHAPENAME;
	static const int NUMSIDES;
	// Constructors
	Square();
	Square(const double sideLength);
	// Getters
	int getNumSides() const override;
	std::string getShapeName() const override;
	// Print shape information
	void printShapeDimensions() const override;

private:
	// Length of each side of the square
	double m_sideLength;
	// Private method to calculate area
	double calculateArea()
	{
		return m_sideLength * m_sideLength;
	}
	// Private method to calculate perimeter
	double calculatePerimeter()
	{
		return 4 * m_sideLength;
	}
};
















#endif