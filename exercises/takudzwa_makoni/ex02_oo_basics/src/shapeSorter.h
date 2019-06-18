#ifndef SHAPESORTER_H
#define SHAPESORTER_H
#include <memory>
#include <vector>

#include "shape.h"

// << OPERATOR OVERLOAD FOR SHAPE CLASS
std::ostream& operator << (std::ostream& stream, const shape& other) {

	stream << "name: " << other.name() << ", area: " << other.area() << ", perimeter: " << other.perimeter() << ", sides: " << other.numOfSides();
	return stream;

}

namespace {

	bool comparePerim(const std::unique_ptr<shape>& a, const std::unique_ptr<shape>& b) { return a->perimeter() < b->perimeter(); }
	bool compareArea(const std::unique_ptr<shape>& a, const std::unique_ptr<shape>& b) { return a->area() < b->area(); }
}


class shapeSorter {

private:
	//int chosenNumOfSides;
	//std::string chosenType;
	std::vector<std::unique_ptr<shape>> shapes;
	

public:


	void printMatchForSide(int chosenNumOfSides) {
	
		std::cout << "\nMATCHES FOR SIDE \"" << chosenNumOfSides <<"\"\n";
		for (size_t i = 0; i != shapes.size(); i++)

		{
			if (shapes[i]->numOfSides() == chosenNumOfSides) { std::cout << *(shapes[i]) << " "; };
		}

		std::cout << "\n\n";

	};

	void printMatchForType(std::string chosenType) {

		std::cout << "\nMATCHES FOR TYPE \"" << chosenType << "\"\n";
		for (size_t i = 0; i != shapes.size(); i++){
		std::transform(chosenType.begin(), chosenType.end(), chosenType.begin(), std::toupper);
		{
			//works so that if searchword is triangle, will find all matches. e.g. isosceles-triangle or equilateral-triangle etc.
			if (shapes[i]->name().find(chosenType) != std::string::npos ) { std::cout << *(shapes[i]) << "\n"; }
			 };
		}

		std::cout << "\n\n";

	};



	void printOrderForArea() {

		std::cout << "AREAS BY DESCENDING ORDER:\n";
		std::sort(shapes.begin(), shapes.end(), compareArea);
		for (const auto& a : shapes) {
			std::cout << *a << "\n";
		}

		std::cout << "\n\n";


	};

	void printOrderForPerim() {

		std::cout << "PERIMETERS BY DESCENDING ORDER:\n";
		std::sort(shapes.begin(), shapes.end(), comparePerim);
		for (const auto& a : shapes) {
			std::cout << *a << "\n";
		}

		std::cout << "\n\n";

	};

	shapeSorter(std::vector<std::unique_ptr<shape>>&& shapesContainer) : shapes(std::move(shapesContainer)) {}

};

#endif
