#!/usr/bin/env python3
import unittest
from collections import Counter


#class Tester(unittest.TestCase):
    #def test_on_import_gui_flag_is_set_to_false_here(self):
        #self.assertEqual(False, mantid.__gui__)

class WordCounter:
	def __init__(self, file_path):
		self.file_path = file_path
		self.lines = None
		self.words = None
		self.sorted_words = None
	def read_file(self):
		with open(self.file_path, 'r') as f:
			self.lines = f.readlines()
	def split_lines(self):
		self.words = [line.split(' ') for line in self.lines]
	def process_words(self):
		self.words = [[[letter.lower() for letter in word if letter.isalpha()] for word in line if len(word) > 4] for line in self.words]
	def count_and_sort(self):
		counter = Counter(self.words)
		self.sorted_words = dict(sorted(counter.items(), key=lambda item: item[1]))
	def output_results(self):
		print("Word      Usage")
		for k,v in self.sorted_words.items():
			print(k + " "*(10 - len(k)) + str(v))


def main():
	file_path = ""


if __name__ == "__main__":
	main()
