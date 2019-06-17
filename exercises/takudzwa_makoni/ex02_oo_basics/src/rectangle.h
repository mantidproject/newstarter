#ifndef RECTANGLE_H
#define RECTANGLE_H



class rectangle : public shape {

private:

	const std::string m_name = "RECTANGLE"; 
	const int m_numOfSides = 4;
	double m_sideWidth, m_sideHeight;

public:

	virtual int numOfSides() const override{ return m_numOfSides; }
	virtual std::string name() const override{ return m_name; }

	virtual double area() const override { return m_sideHeight * m_sideWidth; }
	virtual double perimeter() const override { return (2 * m_sideWidth) + (2 * m_sideHeight); }

	rectangle(double width, double height) : m_sideWidth(width), m_sideHeight(height) {};

};

#endif