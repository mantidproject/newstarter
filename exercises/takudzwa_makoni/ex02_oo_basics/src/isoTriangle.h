#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H



class isoTriangle : public shape { // isosceles triangle class

private:

	static std::string m_name;
	const unsigned int m_numOfSides = 3;
	double m_base, m_height;

public:

	virtual unsigned int numOfSides() const override{ return m_numOfSides; }
	virtual std::string name() const override{ return m_name; }

	virtual double area() const override { return 0.5 * m_base* m_height; }
	virtual double perimeter() const override { return 2 * (sqrt(m_height * m_height) + ((m_base * m_base) / 4)); }

	isoTriangle(double base, double height) : m_base(base), m_height(height) {};
	

};

#endif