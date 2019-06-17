#ifndef SQUARE_H
#define SQUARE_H



class square : public shape {

private:

	static std::string m_name;
	const unsigned int m_numOfSides = 4;
	double m_length;

public:
	
	virtual unsigned int numOfSides() const override{ return m_numOfSides; }
	virtual std::string name() const override { return m_name; }

	virtual double area() const override { return m_length * m_length; }
	virtual double perimeter() const override { return 4 * m_length; }

	square(double length) : m_length(length) {
	
	};

};

#endif