/**
 * Skeleton main routine
 */
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>


class Polygon {
    protected:
    int height;
    int base;
    int radius;
    std::string type;
    Polygon (int h, int b) : height {h}, base {b} {};
    Polygon (int r) : radius{r} {};

    public:
    virtual double get_area () =0;
    std::string get_type () {return type;}
    void print () {std::cout << type << " " << get_area() << '\n';}
};

class Circle : public Polygon {
    public:
    Circle (int r) : Polygon(r) {type = "Circle";};
    double get_area () {return 3.14*radius*radius;};
};

class Rectangle: public Polygon {
    public:
    Rectangle (int h, int b) : Polygon(h, b) {type = "Rectangle";};
    double get_area () {return height*base;};
};

class Square: public Polygon {
    public:
    Square (int h) : Polygon(h, h) {type = "Square";};
    double get_area () {return height*base;};
};

class Triangle: public Polygon {
    public:
    Triangle (int h, int b) : Polygon(h, b) {type = "Triangle";};
    double get_area () {return height*base/2;};
};

class ShapeSorter {

    public:
    ShapeSorter() {};       // Chose not to include shapes here becuase I do not have a default initializer for Polygon()

    void sort_by_area(std::vector<Polygon*> &shapes) {      // Modifies the vector by reference, not the best solution in this case
        std::sort(shapes.begin(), shapes.end(), [](auto l, auto r){return l->get_area() < r->get_area();});
    };

    void print_shapes_with_type(const std::vector<Polygon*> &shapes, std::string type) {
        for (Polygon* p : shapes) if (p->get_type()==type) p->print();
    }

    // To implement sort by perimeter, would follow same logic as for area
    // Would use the same technique as I implemented type to implement number of sides? Is there a more automatic alternative?
};

int main(int, char **)
{
    //
    Circle c1 = Circle(3);
    Circle c2 = Circle(5);
    Rectangle r1 {3, 4};
    Rectangle r2 {5, 4};
    Rectangle r3 {6, 4};
    Square s1 {5};
    Square s2 {6};
    Triangle t1 {6, 6};
    Triangle t2 {4, 5};

    std::vector<Polygon*> shapes {&c1, &c2, &r1, &r2, &r3, &s1, &s2, &t1, &t2};
    ShapeSorter SS{};

    std::cout << "Original shape vector:\n";
    for (Polygon* p : shapes) p->print(); 

    SS.sort_by_area(shapes);

    std::cout << "\nSorted shape vector:\n";
    for (Polygon* p : shapes) p->print(); 

    std::cout << "\nSingle type shape vector:\n";
    SS.print_shapes_with_type(shapes, "Rectangle");
}
