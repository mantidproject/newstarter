'''
Write a command line program that will:

Take a filename of an ascii file as an argument (you can use the example file here)

Load that ascii file.

Count the number of occurrences of unique words (longer than 4 characters and split hyphenated words, treating each part as different words). It should be case and punctuation insensitive. You only need to consider the following punctuation characters .,?'"!(): (hint: you will need a backslash escape character for the double-quote)

Consider handling of common error cases, such as the wrong file name specified. Return error and status information to the user of the command line tool.

Print the results to screen showing the unique words and the number of uses in descending order of usage, e.g.


'''

import argparse
import re
import numpy as np

def get_user_arguments():
	# take in filename from user in command line
	parser = argparse.ArgumentParser(
		prog='top',
		description='read ascii file')
	parser.add_argument('filename', nargs='+')
	# give option to show top number of lines
	parser.add_argument('-l', '--lines', type=int)
	args = parser.parse_args()
	return args.filename[0], args.lines

def read_file(filename):
	f = open(filename, 'r')  # 'r' = read
	linesRaw = f.read()
	# separate punctuation
	lines = re.sub(r'(\W+)', lambda x: ' '+x.group(0)+' ', linesRaw).split()
	#force all strings to be lowercase
	lines = [i.lower() for i in lines]
	# words longer than 4 characters
	lines = [x for x in lines if len(x)>4]
	f.close()
	return lines

def get_unique_words(lines):
	values, counts = np.unique(lines, return_counts=True)
	return values, counts

def main():
	# Ask for filename from user
	filename, numlines = get_user_arguments()
	# Check if file exists
	try:
		lines = read_file(filename)
	except FileNotFoundError:
		print("File not found, please check file!")
		exit()
		# Cant find the file so exit the code

	# Sort the words by their frequency in the file
	values, counts = get_unique_words(lines)
	sortedValuesCounts = [x for x in sorted(zip(counts,values),reverse=True)]

	# print out words in descending order of frequency
	print('Word    Usage')
	for usage, word in sortedValuesCounts[0:numlines]:
		print(word, usage)
	pass


if __name__ == "__main__":
	main()
