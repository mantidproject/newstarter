/**
 * Skeleton main routine
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//.h files 
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "shapesorter.h"

//*int main(int, char **)

void SaveRandomShapes(){
	//Base class to dervice class
	std::vector<Shape*> shapes; 

	//sqaure 
	//Square square1(4);
	shapes.push_back(new Square(4));
	shapes.push_back(new Square(7));

	//triangle
	shapes.push_back(new Triangle(7, 3));
	shapes.push_back(new Triangle(12, 4));

	//rectangle
	shapes.push_back(new Rectangle(10,5));
	shapes.push_back(new Rectangle(8,4));

	//circle
	shapes.push_back(new Circle(6));
	shapes.push_back(new Circle(8));

	//Rectangle r = dynamic_cast<Rectangle*>(shapes[0]);
	//shapes[0]Area();


	for(int i=0; i<shapes.size(); ++i){
		//std::cout << shapes[i]->getType() << " --> Perimeter: " << shapes[i]->getPerimeter() << endl;

		std:: cout << " Shape type: " << shapes[i]->getType() << ", Number of sides: " << shapes[i]->getSides() << ", Perimeter: " << shapes[i]->getPerimeter() << ", Area: " << shapes[i]->getArea() << endl;
	}

}


//base class
int main()
{


	/*for (auto i = shapes.begin(); i != shapes.end(); ++i){
		cout << (*i) << endl;
		}
	*.//cout << "area " << square1.Perimeter() << endl;
	*/
	SaveRandomShapes();

	string por;
	cin >> por;
	
	return 0;
}//

