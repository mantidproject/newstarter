#!/usr/bin/env python3
from math import pi

class Rectangle:
	def __init__(self, s1, s2, name):
		self.shape = "Rectangle"
		self.num_sides = 4
		self.name = name
		self.side1 = s1
		self.side2 = s2
	def calculate_area(self):
		self.area = self.side1 * self.side2
	def calculate_perimeter(self):
		self.perimeter = 2*(self.side1 + self.side2)

class Square(Rectangle):
	def __init__(self, s1):
		super().__init__(s1, s1)
		self.shape = "Square"

class Circle:
	def __init__(self, radius, name):
		self.shape = "Circle"
		self.num_sides = 1
		self.radius = radius
		self.name = name
	def calculate_area(self):
		self.area = pi*self.radius**2
	def calculate_perimeter(self):
		self.perimeter = 2*pi*self.radius

class Triangle:
	def __init__(self, base, height, name):
		self.shape = "Triangle"
		self.num_sides = 3
		self.base = base
		self.height = height
		self.name = name
	def calculate_area(self):
		self.area = 0.5*self.base*self.height
	def calculate_perimeter(self):
		self.perimeter = self.base + 2*(self.height**2 + (self.base**2)/4)**0.5

def main():
	pass


if __name__ == "__main__":
	main()
