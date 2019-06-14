#ifndef SHAPESORTER_H
#define SHAPESORTER_H

#include "shape.h"

namespace {

	bool comparePerim(const shape* a, const shape* b) { return a->getPerimeter() < b->getPerimeter(); }
	bool compareArea(const shape* a, const shape* b) { return a->getArea() < b->getArea(); }
}


struct shapeSorter {

public:
	int chosenNumOfSides;
	std::string chosenType;
	std::vector<shape*> shapes;

	void printMatchForSide() {
	
		std::cout << "\nMATCHES FOR SIDE: " << chosenNumOfSides <<"\n";
		for (std::vector<shape*>::size_type i = 0; i != shapes.size(); i++)

		{
			if (shapes[i]->getNumOfSides() == chosenNumOfSides) { std::cout << shapes[i]->getName() << " "; };
		}

		std::cout << "\n\n";
		std::cin.get();
	};

	void printMatchForType() {

		std::cout << "\nMATCHES FOR TYPE: " << chosenType << "\n";
		for (std::vector<shape*>::size_type i = 0; i != shapes.size(); i++)

		{
			//works so that if searchword is triangle, will find all matches. e.g. isosceles-triangle or equilateral-triangle etc.
			if (shapes[i]->getName().find(chosenType) != std::string::npos ) { std::cout << shapes[i]->getName() << " "; };
		}

		std::cout << "\n\n";
		std::cin.get();
	};



	void printOrderForArea() {

		std::cout << "AREAS BY DESCENDING ORDER:\n";
		std::sort(shapes.begin(), shapes.end(), compareArea);
		for (auto a : shapes) {
			std::cout << a->getName() << " ";
		}

		std::cout << "\n\n";
		std::cin.get();

	};

	void printOrderForPerim() {

		std::cout << "PERIMETERS BY DESCENDING ORDER:\n";
		std::sort(shapes.begin(), shapes.end(), comparePerim);
		for (auto a : shapes) {
			std::cout << a->getName() << " ";
		}

		std::cout << "\n\n";
		std::cin.get();
	};

	shapeSorter::shapeSorter() {
	
		chosenNumOfSides = 4;
		chosenType = "square";
	}

};

#endif