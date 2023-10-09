/**
 * Skeleton main routine
 */
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

class Polygon {
 protected:
  int height {1};
  int base {1};
  int radius {1};
  std::string type;
  Polygon(int h, int b) : height {h}, base {b} {};
  explicit Polygon(int r) : radius{r} {};

 public:
  virtual int get_area() const = 0;
  std::string get_type () const {return type;}
  void print() const {std::cout << type << " " << get_area() << '\n';}
};

class Circle : public Polygon {
 public:
  explicit Circle(int r) : Polygon(r) {type = "Circle";}
  int get_area () const {return 3.14*radius*radius;}
};

class Rectangle: public Polygon {
 public:
  Rectangle(int h, int b) : Polygon(h, b) {type = "Rectangle";}
  int get_area() const {return height*base;}
};

class Square: public Polygon {
 public:
  explicit Square(int h) : Polygon(h, h) {type = "Square";}
  int get_area () const {return height*base;}
};

class Triangle: public Polygon {
 public:
  Triangle(int h, int b) : Polygon(h, b) {type = "Triangle";}
  int get_area () const {return height*base/2;}
};

class ShapeSorter {
 public:
  ShapeSorter() {}

  void sort_by_area(std::vector<Polygon*> *shapes) {
    std::sort(shapes->begin(), shapes->end(), [](auto l, auto r){
        return l->get_area() < r->get_area();
        });
  }

  void print_shapes_with_type(
      const std::vector<Polygon*> *shapes, std::string type
      ) {
      for (auto const& p : *shapes) if (p->get_type() == type) p->print();
  }
};

int main(int, char **) {
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
    for (auto const& p : shapes) p->print();

    std::vector<Polygon*> *shapes_p = &shapes;  // Init pointer
    SS.sort_by_area(shapes_p);

    std::cout << "\nSorted shape vector:\n";
    for (auto const& p : shapes) p->print();

    std::cout << "\nSingle type shape vector:\n";
    SS.print_shapes_with_type(shapes_p, "Rectangle");
}
