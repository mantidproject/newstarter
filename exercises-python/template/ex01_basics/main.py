#!/usr/bin/env python3

def read_ascii_file(filename):
	try:
		f = open(filename, 'r')
		return f.read()
	except FileNotFoundError as e:
		raise FileNotFoundError(f"The file {filename} was not found.")

def main():
	read_ascii_file("file.txt")


if __name__ == "__main__":
	main()


