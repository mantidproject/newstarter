#ifndef SHAPES_H_
#define SHAPES_H_

#include <string>

namespace constants{
	const std::string CIRCLE_NAME = "circle";
	const int CIRCLE_SIDES = 1;

	const std::string TRIANGLE_NAME = "triangle";
	const int TRIANGLE_SIDES = 3;

	const std::string RECT_NAME = "rectangle";
	const int RECT_SIDES = 4;

	const std::string SQUARE_NAME = "square";

	const float PI = 3.14159;
}

//Base class
class Shape
{
	protected:
		std::string name;
		const int sides;
	public:
		Shape( const std::string& name, const int& s);
		std::string getType();
		int getSides();
		virtual double getPerim() = 0;
		virtual double getArea() = 0;

};

//Rectangle class
class Rect: public Shape
{
	protected:
		float width, height;
	public:
		Rect(double& w, double& h);
		double getArea();
		double getPerim();
};

//Square class
class Square: public Rect
{
	public:
		Square(double& w);
};

//Triangle class
class Triangle: public Shape
{
	protected:
		float base, height;
	public:
		Triangle(double& b, double& h);
		double getArea();
		double getPerim();
};

//Circle class
class Circle: public Shape
{
	protected:
		double radius;
	public:
		Circle(double& r);
		double getArea();
		double getPerim();
};

#endif // SHAPES_H_
