#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeSorter.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>

int main(int, char **)
{
    std::vector<std::unique_ptr<Shape> > shapes;

    shapes.emplace_back(std::make_unique<Circle>(10));
    shapes.emplace_back(std::make_unique<Square>(10));
    shapes.emplace_back(std::make_unique<Rectangle>(10,10));
    shapes.emplace_back(std::make_unique<Triangle>(10,10));

    //Start a menu for the things we need to check
    char response;
    ShapeSorter sorter;
                    std::string response2;
    do{
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1 - Print out shapes that match a chosen type" << std::endl;
        std::cout << "2 - Print out the Shapes that match a chosen number of sides" << std::endl;
        std::cout << "3 - Print out the Shapes in order of Area descending" << std::endl;
        std::cout << "4 - Print out the Shapes in order of perimeter descending" << std::endl;
        std::cout << "q - Quit the program" << std::endl;
        std::cin >> response;
        switch(response){
            case '1':
                //Print out shapes that match a chosen type                
                std::cout << "What type of shape should be printed?" << std::endl;
                std::cin >> response2;

                sorter.printOutShapesOfType(shapes, response2);
                break;
            case '2':
                //Print out the shapes that match a chosen number of sides                
                int response3;              

                std::cout << "How many sides?" << std::endl;
                std::cin >> response3;

                sorter.printOutShapesOfSides(shapes, response3);
                break;
            case '3':
                //Print out the Shapes in order if Area descending
                sorter.printOutShapesInOrderOfArea(shapes);
                break;
            case '4':
                //Print out the shapes in order of perimeter descending
                sorter.printOutShapesInOrderOfPerimeter(shapes);
                break;
        }
    }while(response != 'q' || response != 'Q');
    

}