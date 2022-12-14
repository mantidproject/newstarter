#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

class Shape {
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

class Square : public Shape {
    public:
        Square(double side1) : side1{side1}, Shape(2) {}

        std::string getType() {
            return "Square";
        }

        int getSidesCount() {
            return 2;
        }
        
        double getArea() {
            return side1 * side1;
        }

        double getPerimeter() {
            return 4*side1;
        }

        std::string toString() {
            return "Square(side=" + std::to_string(side1) + ")";
        }
    private:
        double side1;
};

class Rectangle : public Shape {
    public:
        Rectangle(double side1, double side2) : side1{side1}, side2{side2}, Shape(2) {}

        std::string getType() {
            return "Rectangle";
        }

        int getSidesCount() {
            return 2;
        }
        
        double getArea() {
            return side1 * side2;
        }

        double getPerimeter() {
            return 2*side1 + 2*side2; 
        }

        std::string toString() {
            return "Rectangle(side1=" + std::to_string(side1) + ", side2=" + std::to_string(side2) + ")";
        }
    private:
        double side1, side2;
};

class Circle : public Shape {
    public:
        Circle(double radius) : radius{radius}, Shape(0) {}

        std::string getType() {
            return "Circle";
        }

        int getSidesCount() {
            return 0;
        }
        
        double getArea() {
            return pi*radius*radius;
        }

        double getPerimeter() {
            return 2*pi*radius; 
        }

        std::string toString() {
            return "Circle(radius=" + std::to_string(radius) + ")";
        }
    private:
        double radius;
        const double pi = 3.14159265358979323846;

};

class Triangle : public Shape {
    public:
        Triangle(double height, double base) : height{height}, base{base}, Shape(3) {}

        std::string getType() {
            return "Triangle";
        }

        int getSidesCount() {
            return 3;
        }
        
        double getArea() {
            return 0.5*height*base;
        }

        double getPerimeter() {
            return base + 2 * std::sqrt(height * height + (base * base) / 4);
        }

        std::string toString() {
            return "Triangle(height=" + std::to_string(height) + ", base=" + std::to_string(base) + ")";
        }
    private:
        double height, base;
};

class ShapeSorter {
    public:
        ShapeSorter(const std::vector<Shape*> & shapes) : shapes{shapes} {}

        void printShapesWithType(const std::string& type) {
            for(auto shape: shapes) {
                if(shape->getType() == type){
                    std::cout<<shape->toString()<<" ";
                }
            }
            std::cout<<"\n";
        }

        void printShapesWithSides(const int& sidesCount) {
            for(auto shape: shapes) {
                if(shape->getSidesCount() == sidesCount){
                    std::cout<<shape->toString()<<" ";
                }
            }
            std::cout<<"\n";
        }

        void printOrderedShapesByArea() {
            auto sortedShapes = shapes;

            std::sort(
                sortedShapes.begin(), sortedShapes.end(),
                [](Shape* left, Shape* right) {
                    return left->getArea() > right->getArea();
                }
            );

            for(auto shape: sortedShapes) {
                std::cout<<shape->toString()<<" ";
            }
            std::cout<<"\n";
        }

        void printOrderedShapesByPerimeter() {
            auto sortedShapes = shapes;

            std::sort(
                sortedShapes.begin(), sortedShapes.end(),
                [](Shape* left, Shape* right) {
                    return left->getPerimeter() > right->getPerimeter();
                }
            );

            for(auto shape: sortedShapes) {
                std::cout<<shape->toString()<<" ";
            }
            std::cout<<"\n";
        }

    private:
        const std::vector<Shape*>& shapes;
};

int main(int, char **)
{
    Shape* sq1 = new Square(2);

    // std::cout<<sq1->getType()<<std::endl;
    // std::cout<<sq1->getSidesCount()<<std::endl;
    // std::cout<<sq1->getArea()<<std::endl;
    // std::cout<<sq1->getPerimeter()<<std::endl;

    Shape* rect1 = new Rectangle(2, 4);
    Shape* rect2 = new Rectangle(4, 14);

    // std::cout<<rect1->getType()<<std::endl;
    // std::cout<<rect1->getSidesCount()<<std::endl;
    // std::cout<<rect1->getArea()<<std::endl;
    // std::cout<<rect1->getPerimeter()<<std::endl;

    Shape* c1 = new Circle(2);
    Shape* c2 = new Circle(10);

    // std::cout<<c1->getType()<<std::endl;
    // std::cout<<c1->getSidesCount()<<std::endl;
    // std::cout<<c1->getArea()<<std::endl;
    // std::cout<<c1->getPerimeter()<<std::endl;

    Shape* t1 = new Triangle(2, 4);
    Shape* t2 = new Triangle(4, 10);

    // std::cout<<t1->getType()<<std::endl;
    // std::cout<<t1->getSidesCount()<<std::endl;
    // std::cout<<t1->getArea()<<std::endl;
    // std::cout<<t1->getPerimeter()<<std::endl;

    std::vector<Shape*> shapes;

    shapes.push_back(sq1);
    shapes.push_back(rect1);
    shapes.push_back(rect1);
    shapes.push_back(c1);
    shapes.push_back(c2);
    shapes.push_back(t1);
    shapes.push_back(t2);

    ShapeSorter sorter(shapes);
    sorter.printShapesWithType("Rectangle");
    sorter.printShapesWithSides(2);
    sorter.printOrderedShapesByArea();
    sorter.printOrderedShapesByPerimeter();

    return 0;
}