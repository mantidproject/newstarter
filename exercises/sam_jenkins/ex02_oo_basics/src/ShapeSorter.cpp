#include "Shapes.h"
#include "ShapeSorter.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
const int COLUMN_WIDTH1 = 9;
const int COLUMN_WIDTH2 = 4;

bool compareArea(const Shapes* s1, const Shapes *s2)
{
	return(s1->calcArea() > s2->calcArea());
}

bool comparePerimiter(const Shapes* s1, const Shapes *s2)
{
	return(s1->calcPerimiter() > s2->calcPerimiter());
}

void ShapeSorter::typePrint(const string &type, const ShapeVec &shapes)
{
	for (const auto &shape : shapes) {
		if (shape->getType() == type) {
			cout << " Type: " << setw(COLUMN_WIDTH1) << shape->getType() << " Sides: ";
			cout << setw(COLUMN_WIDTH2) << shape->getSides() << " Area: " << setw(COLUMN_WIDTH1) << shape->calcArea();
			cout << " Perimiter: " << setw(COLUMN_WIDTH1) << shape->calcPerimiter() << endl;
		}

	}
	cout << endl;
}

void ShapeSorter::sidesPrint(const int &sides, const ShapeVec &shapes)
{
	for (const auto &shape : shapes) {
		if (shape->getSides() == sides) {
			cout << " Type: " << setw(COLUMN_WIDTH1) << shape->getType() << " Sides: ";
			cout << setw(COLUMN_WIDTH2) << shape->getSides() << " Area: " << setw(COLUMN_WIDTH1) << shape->calcArea();
			cout << " Perimiter: " << setw(COLUMN_WIDTH1) << shape->calcPerimiter() << endl;
		}

	}	
	cout << endl;
}

void ShapeSorter::areaSort(ShapeVec &shapes)
{
	sort(shapes.begin(), shapes.end(), [](const unique_ptr<Shapes> &left, const unique_ptr<Shapes> &right) {
		return left->calcArea() > right->calcArea();
	});
	for (const auto &shape : shapes) {
		cout << " Type: " << setw(COLUMN_WIDTH1) << shape->getType() << " Sides: ";
		cout << setw(COLUMN_WIDTH2) << shape->getSides() << " Area: " << setw(COLUMN_WIDTH1) << shape->calcArea();
		cout << " Perimiter: " << setw(COLUMN_WIDTH1) << shape->calcPerimiter() << endl;
	}
	cout << endl;
}
void ShapeSorter::perimiterSort(ShapeVec &shapes)
{
	sort(shapes.begin(), shapes.end(), [](const unique_ptr<Shapes> &left, const unique_ptr<Shapes> &right) {
		return left->calcPerimiter() > right->calcPerimiter();
	});
	for (const auto &shape : shapes) {
		cout << " Type: " << setw(COLUMN_WIDTH1) << shape->getType() << " Sides: ";
		cout << setw(COLUMN_WIDTH2) << shape->getSides() << " Area: " << setw(COLUMN_WIDTH1) << shape->calcArea();
		cout << " Perimiter: " << setw(COLUMN_WIDTH1) << shape->calcPerimiter() << endl;
	}
	cout << endl;
}

