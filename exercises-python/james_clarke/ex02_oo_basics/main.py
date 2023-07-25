from Shapes import *
from ShapeSorter import *


def main():
	shapes = [Square(2), Square(2.5), Rectangle(1, 2), Rectangle(2, 1), Triangle(2, 3), Triangle(3.1, 2.3), Circle(4.1)]
	sorter = ShapeSorter(shapes)
	sorter.of_type(type(Square(2)))
	print("")
	sorter.with_sides(4)
	print("")
	sorter.area_descending()
	print("")
	sorter.perimeter_descending()


if __name__ == "__main__":
	main()
