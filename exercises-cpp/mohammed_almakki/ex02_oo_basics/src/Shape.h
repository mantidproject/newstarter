#pragma once

#include <string>

class Shape
{
public:
    virtual std::string getType() = 0;
    virtual int getSidesCount() = 0;
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    virtual std::string toString() = 0;

    Shape(int noOfSides) : noOfSides{noOfSides} {}

private:
    int noOfSides;
};

class Square : public Shape
{
public:
    Square(double side1) : side1{side1}, Shape(2) {}

    std::string getType()
    {
        return "Square";
    }

    int getSidesCount()
    {
        return 2;
    }

    double getArea()
    {
        return side1 * side1;
    }

    double getPerimeter()
    {
        return 4 * side1;
    }

    std::string toString()
    {
        return "Square(side=" + std::to_string(side1) + ")";
    }

private:
    double side1;
};

class Rectangle : public Shape
{
public:
    Rectangle(double side1, double side2) : side1{side1}, side2{side2}, Shape(2) {}

    std::string getType()
    {
        return "Rectangle";
    }

    int getSidesCount()
    {
        return 2;
    }

    double getArea()
    {
        return side1 * side2;
    }

    double getPerimeter()
    {
        return 2 * side1 + 2 * side2;
    }

    std::string toString()
    {
        return "Rectangle(side1=" + std::to_string(side1) + ", side2=" + std::to_string(side2) + ")";
    }

private:
    double side1, side2;
};

class Circle : public Shape
{
public:
    Circle(double radius) : radius{radius}, Shape(0) {}

    std::string getType()
    {
        return "Circle";
    }

    int getSidesCount()
    {
        return 0;
    }

    double getArea()
    {
        return pi * radius * radius;
    }

    double getPerimeter()
    {
        return 2 * pi * radius;
    }

    std::string toString()
    {
        return "Circle(radius=" + std::to_string(radius) + ")";
    }

private:
    double radius;
    const double pi = 3.14159265358979323846;
};

class Triangle : public Shape
{
public:
    Triangle(double height, double base) : height{height}, base{base}, Shape(3) {}

    std::string getType()
    {
        return "Triangle";
    }

    int getSidesCount()
    {
        return 3;
    }

    double getArea()
    {
        return 0.5 * height * base;
    }

    double getPerimeter()
    {
        return base + 2 * std::sqrt(height * height + (base * base) / 4);
    }

    std::string toString()
    {
        return "Triangle(height=" + std::to_string(height) + ", base=" + std::to_string(base) + ")";
    }

private:
    double height, base;
};
