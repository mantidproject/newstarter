#pragma once

#include <string>
#include <math.h>

enum class ShapeType { Shape, Rectangle, Square, Circle, Triangle };

class Shape
{
public:
    virtual inline double getArea() const = 0;
    virtual inline double getPerimeter() const = 0;

    virtual inline ShapeType getType() const = 0;
    virtual inline std::string toString() const = 0;

    inline int getSidesCount() const {
        return noOfSides;
    }

    Shape(const int& noOfSides) : noOfSides{noOfSides} {}

    private:
        const int noOfSides;
};

class Rectangle : public Shape
{
public:
    Rectangle(const double& side1, const double& side2) : side1{side1}, side2{side2}, Shape(2) {}

    inline ShapeType getType() const override
    {
        return ShapeType::Rectangle;
    }

    inline double getArea() const override
    {
        return side1 * side2;
    }

    inline double getPerimeter() const override
    {
        return 2 * side1 + 2 * side2;
    }

    inline std::string toString() const override
    {
        return "Rectangle(side1=" + std::to_string(side1) + ", side2=" + std::to_string(side2) + ")";
    }

private:
    double side1;
    double side2;
};

class Square : public Rectangle
{
public:
    Square(double side1) : side1{side1}, Rectangle(side1, side1) {}

    inline ShapeType getType() const override
    {
        return ShapeType::Rectangle;
    }

    inline std::string toString() const override
    {
        return "Square(side=" + std::to_string(side1) + ")";
    }

private:
    double side1;
};

class Circle : public Shape
{
public:
    Circle(double radius) : radius{radius}, Shape(0) {}

    inline ShapeType getType() const override
    {
        return ShapeType::Circle;
    }

    inline double getArea() const override
    {
        return M_PI * radius * radius;
    }

    inline double getPerimeter() const override
    {
        return 2 * M_PI * radius;
    }

    inline std::string toString() const override
    {
        return "Circle(radius=" + std::to_string(radius) + ")";
    }

private:
    double radius;
};

class Triangle : public Shape
{
public:
    Triangle(double height, double base) : height{height}, base{base}, Shape(3) {}

    inline ShapeType getType() const override
    {
        return ShapeType::Triangle;
    }

    inline double getArea() const override
    {
        return 0.5 * height * base;
    }

    inline double getPerimeter() const override
    {
        return base + 2 * std::sqrt(height * height + (base * base) / 4);
    }

    inline std::string toString() const override
    {
        return "Triangle(height=" + std::to_string(height) + ", base=" + std::to_string(base) + ")";
    }

private:
    double height;
    double base;
};
