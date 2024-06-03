#!/usr/bin/env python3

def read_ascii_file(param):
	try:
		f = open(param, 'r')
		return f.read()
	except FileNotFoundError:
		print("Oops! That was not a valid file. Try again...")

def main():
	read_ascii_file("file.txt")


if __name__ == "__main__":
	main()


