#include "Shapes.h"
#include "ShapeSorter.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using std::vector; using std::string; using std::cout;
using std::endl; using std::sort; using std::setw;


bool compareArea(const Shapes* s1, const Shapes *s2)
{
	return(s1->calcArea() > s2->calcArea());
}

bool comparePerimiter(const Shapes* s1, const Shapes *s2)
{
	return(s1->calcPerimiter() > s2->calcPerimiter());
}

void ShapeSorter::typePrint(string type, vector<Shapes*> shapes)
{
	for (vector<Shapes*>::size_type i = 0; i!= shapes.size(); ++i){
		if (shapes[i]->getType() == type) {
			cout << " Type: " << setw(9)<<shapes[i]->getType() << " Sides: " << setw(4) << shapes[i]->getSides() << " Area: " << setw(9) << shapes[i]->calcArea() << " Perimiter: " << setw(9) << shapes[i]->calcPerimiter() << endl;
		}

	}
	cout << endl;
}

void ShapeSorter::sidesPrint(int sides, vector<Shapes*> shapes) 
{
	for (vector<Shapes*>::size_type i = 0; i != shapes.size(); ++i) {
		if (shapes[i]->getSides() == sides) {
			cout << " Type: " << setw(9) << shapes[i]->getType() << " Sides: " << setw(4) << shapes[i]->getSides() << " Area: " << setw(9) << shapes[i]->calcArea() << " Perimiter: " << setw(9) << shapes[i]->calcPerimiter() << endl;
		}

	}	
	cout << endl;
}

void ShapeSorter::areaSort(vector<Shapes*>shapes)
{
	sort(shapes.begin(), shapes.end(), compareArea);
	for (vector<Shapes*>::size_type i = 0; i != shapes.size(); ++i) {
		cout << " Type: " << setw(9) << shapes[i]->getType() << " Sides: " << setw(4) << shapes[i]->getSides() << " Area: " << setw(9) << shapes[i]->calcArea() << " Perimiter: " << setw(9) << shapes[i]->calcPerimiter() << endl;
	}
	cout << endl;
}
void ShapeSorter::perimiterSort(vector<Shapes*>shapes) 
{
	sort(shapes.begin(), shapes.end(), comparePerimiter);
	for (vector<Shapes*>::size_type i = 0; i != shapes.size(); ++i) {
		cout << " Type: " << setw(9) << shapes[i]->getType() << " Sides: " << setw(4) << shapes[i]->getSides() << " Area: " << setw(9) << shapes[i]->calcArea() << " Perimiter: " << setw(9) << shapes[i]->calcPerimiter() << endl;
	}
	cout << endl;
}

