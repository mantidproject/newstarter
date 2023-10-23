'''
Write a command line program that:

Has classes to allow number of shapes to be defined: square (side1), rectangle(side1, side2), circle(radius), triangle(height, base).

Each shape class should know it’s type (“Square”), how many sides it has.

Each shape needs to be able to calculate it’s perimeter and area. For the triangle you can assume it is isoceles and the perimeter can be computed using
, where
 is the base and
 is the height.

Within the Main method create a variety of the shapes and put them in a list

Create a class ShapeSorter which should contain four methods

Print out the Shapes that match a chosen type

Print out the Shapes that match a chosen number of sides

Print out the Shapes in order of area descending

Print out the Shapes in order of perimeter descending
'''

# Imports here
import numpy as np

# Shape Classes here
class square():
	def __init__(self, side1):
		self.side1 = side1
		self.type = "Square"
		self.number_sides = 4
		self.Calc_perimeter()
		self.Calc_area()

	def printinfo(self):
		print(f"This square has side {self.side1}, side number {self.number_sides}, perimeter {self.p}, area {self.a}")

	def Calc_perimeter(self):
		self.p = 4 * self.side1
	def Calc_area(self):
		self.a = self.side1**2
class rectangle():
	def __init__(self, side1, side2):
		self.side1 = side1
		self.side2 = side2
		self.type = "Rectangle"
		self.number_sides = 4
		self.Calc_perimeter()
		self.Calc_area()

	def printinfo(self):
		print(f"This rectangle has sides {self.side1} and {self.side2}, side number {self.number_sides}, perimeter {self.p}, area {self.a}")
	def Calc_perimeter(self):
		self.p = 2 * self.side1 + 2 * self.side2
	def Calc_area(self):
		self.a = self.side1 * self.side2
class circle():
	def __init__(self, radius):
		self.radius = radius
		self.type = "Circle"
		self.number_sides = 1
		self.Calc_perimeter()
		self.Calc_area()

	def printinfo(self):
		print(f"This circle has radius {self.radius}, side number {self.number_sides}, perimeter {self.p}, area {self.a}")
	def Calc_perimeter(self):
		self.p = 2 * np.pi * self.radius
	def Calc_area(self):
		self.a = np.pi * self.radius**2
class triangle():
	def __init__(self, height, base):
		self.height = height
		self.base = base
		self.type = "Triangle"
		self.number_sides = 3
		self.Calc_perimeter()
		self.Calc_area()

	def printinfo(self):
		print(f"This triangle has base {self.base} and height {self.height}, side number {self.number_sides}, perimeter {self.p}, area {self.a}")
	def Calc_perimeter(self):
		self.p = self.base + 2*np.sqrt(self.height**2 + (self.base**2 / 4))
	def Calc_area(self):
		self.a = 1/2 * self.base * self.height

class shapesorter():
	def __init__(self, ShapeList):
		self.ShapeList = ShapeList
	def PrintType(self, type):
		print(f"Printing info on shapes with type: {type}")
		for shape in self.ShapeList:
			if shape.type == type:
				shape.printinfo()
		print("\n")

	def PrintNumSides(self, numsides):
		print(f"Printing info on shapes with number of sides: {numsides}")
		for shape in self.ShapeList:
			if shape.number_sides == numsides:
				shape.printinfo()
		print("\n")

	def SortAreasDes(self):
		print("Printing shapes with descending area:")
		SortedShapeList = sorted(self.ShapeList, key=lambda x: x.a, reverse=True)
		for shape in SortedShapeList:
			shape.printinfo()
		print("\n")

	def SortPerimeterDes(self):
		print("Printing shapes with descending perimeter:")
		SortedShapeList = sorted(self.ShapeList, key=lambda x: x.p, reverse=True)
		for shape in SortedShapeList:
			shape.printinfo()
		print("\n")
def main():
	Triangle = triangle(2,6)
	Circle1 = circle(3)
	Circle2 = circle(12.4)
	Square = square(3.4)
	Rectangle1 = rectangle(2.4,6.3)
	Rectangle2 = rectangle(1, 12)

	ShapeList = [Triangle, Circle1, Circle2, Square, Rectangle1, Rectangle2]
	ShapeSorter = shapesorter(ShapeList)
	ShapeSorter.PrintType("Circle")
	ShapeSorter.PrintNumSides(4)
	ShapeSorter.SortAreasDes()
	ShapeSorter.SortPerimeterDes()


if __name__ == "__main__":
	main()
