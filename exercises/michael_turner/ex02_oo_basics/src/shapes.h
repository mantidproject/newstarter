#ifndef SHAPES_H_
#define SHAPES_H_

#include <string>

namespace constants{
	const std::string CIRCLE_NAME = "circle";
	const int CIRCLE_SIDES = 1;

	const std::string TRIANGLE_NAME = "triangle";
	const int TRIANGLE_SIDES = 3;

    const std::string RECTANGLE_NAME = "rectangle";
    const int RECTANGLE_SIDES = 4;

	const std::string SQUARE_NAME = "square";

	const float PI = 3.14159;
}

//Base class
class Shape
{
	protected:
        std::string type;
		const int sides;
	public:
        Shape( const std::string& name, const int& s);
        std::string getType() const;
        int getSides() const;
        virtual double getPerim() const {return 0;}
        virtual double getArea() const {return 0;}

};

//Rectangle class
class Rectangle: public Shape
{
	protected:
		float width, height;
	public:
        Rectangle(double w, double h);
        double getArea() const;
        double getPerim() const;
};

//Square class
class Square: public Rectangle
{
	public:
        Square(double w);
};

//Triangle class
class Triangle: public Shape
{
	protected:
		float base, height;
	public:
        Triangle(double b, double h);
        double getArea() const;
        double getPerim() const;
};

//Circle class
class Circle: public Shape
{
	protected:
		double radius;
	public:
        Circle(double r);
        double getArea() const;
        double getPerim() const;
};

#endif // SHAPES_H_
