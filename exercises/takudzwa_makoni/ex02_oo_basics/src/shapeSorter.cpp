#include "shapeSorter.h"
#include "shape.h"

//operator function to display shape info.
std::ostream& operator<< (std::ostream& stream, const Shape& obj)
{
	stream << "name: " << obj.shapeType() << ", area: " << obj.area() << ", perimeter: " << obj.perimeter() << ", sides: " << obj.numOfSides();
	return stream;
}

//comparison functions for area and perimeter.
bool comparePerim(const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) { return a->perimeter() < b->perimeter(); }
bool compareArea(const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) { return a->area() < b->area(); }

ShapeSorter::ShapeSorter(std::vector<std::unique_ptr<Shape>>&& shapesContainer) : m_shapes(std::move(shapesContainer)) {};

//display match in vector if any for number of sides.
void ShapeSorter::printMatchForSide(int chosenNumOfSides) const {

	std::cout << "\nMATCHES FOR SIDE \"" << chosenNumOfSides << "\"\n";
	for (size_t i = 0; i != m_shapes.size(); i++)
	{
		if (m_shapes[i]->numOfSides() == chosenNumOfSides) { std::cout << *(m_shapes[i]) << " "; };
	}
	std::cout << "\n\n";
};

//display match in vector if any for shape of chosen type.
void ShapeSorter::printMatchForType(std::string chosenType) const {
	std::cout << "\nMATCHES FOR TYPE \"" << chosenType << "\"\n";
	for (size_t i = 0; i != m_shapes.size(); i++) {

		std::transform(chosenType.begin(), chosenType.end(), chosenType.begin(), [](unsigned char c) -> unsigned char { return ::toupper(c); });

		{
			if (m_shapes[i]->shapeType().find(chosenType) != std::string::npos) { std::cout << *(m_shapes[i]) << "\n"; } //find match in file
		};
	}

	std::cout << "\n\n";

};

//display all vectors from smallest to biggest area.
void ShapeSorter::printOrderForArea()  {

	std::cout << "AREAS BY DESCENDING ORDER:\n";
	std::sort(m_shapes.begin(), m_shapes.end(), compareArea);
	for (const auto& a : m_shapes) {
		std::cout << *a << "\n";
	}
	std::cout << "\n\n";

};

//display all vectors from smallest to biggest perimeter
void ShapeSorter::printOrderForPerim()  {

	std::cout << "PERIMETERS BY DESCENDING ORDER:\n";

	std::sort(m_shapes.begin(), m_shapes.end(), comparePerim);
	for (const auto& a : m_shapes) {
		std::cout << *a << "\n";
	}

	std::cout << "\n\n";

};

	


	




	
