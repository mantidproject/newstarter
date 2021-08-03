#include <iostream>
#include <math.h>
#include <vector>
#include <typeinfo>
#include <algorithm>

class Shape {
    public:
        double area,perimeter;
};
class Square: public Shape {
    public:
        double side1;
        Square(int a){
            side1 = a;
            area = pow(side1,2);
            perimeter = 4*side1;
        }
};
class Rectangle: public Shape  {
    public:
        double side1, side2;
        Rectangle(int a, int b){
            side1 = a;
            area = side1*side2;
            perimeter = 2*(side1+side2);
        }
};
class Circle: public Shape  {
    public:
        double radius;
        Circle(int a){
            radius = a;
            area = pow(radius,2)*3.14;
            perimeter = 2*(radius)*3.14;
        }
};
class Triangle: public Shape  {
    public:
        double base, height;
        Triangle(int a, int b){
            base = a;
            height = b;
            area = base*height*0.5;
            perimeter = base+2*(pow((pow(height,2)+pow(base,2)/4),0.5));
        }
};
bool comp (Shape i, Shape j){ return (i.area<j.area)}
class ShapeSorter {
    public:
        void type(std::vector<Shape> shapes, std::string type){
            for (int i=0; i<=shapes.size();i++){
                if(std::typeid(shapes[i]) == std::typeid(type)){
                    std::cout << shapes[i];
                }
            }
        }
        void type(std::vector<Shape> shapes, std::string sides){
            switch(sides){
                case 1:
                    sides = "Circle";
                    break;
            }
        }
        void area(std::vector<Shape> shapes){
            std::sort (shapes.begin(), shapes.end(), comp);
        }

};
int main()
{
    Square square (4);
    std::vector<Shape> shapes;
    shapes.push_back(square);
    std::cout << shapes[0].area;

}