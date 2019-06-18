#ifndef CIRCLE_H
#define CIRCLE_H



class circle : public shape { // circle class

private:

	
	static const std::string m_name;
	const unsigned int m_numOfSides = 1;
	const double m_pi = 3.14159;
	double m_radius;


public:

	 
	virtual unsigned int numOfSides() const override { return m_numOfSides; }
	virtual std::string name() const override { return m_name; }

	virtual double area() const override { return m_pi * m_radius * m_radius; } //removed override
	virtual double perimeter() const  override { return m_pi * 2 * m_radius; }	//removed override



	circle(double radius) : m_radius(radius) {
	
	};

};

#endif