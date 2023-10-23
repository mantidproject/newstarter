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
#import os.path
def getfilename():
	# take in filename from user in command line
	parser = argparse.ArgumentParser(
		prog='top',
		description='read ascii file')
	parser.add_argument('filename', nargs='+')
	parser.add_argument('-l', '--lines', type=int) # give option to show top number of lines
	args = parser.parse_args()
	print(args)
	print(f"Entered file is: {args.filename}")
	#check_file = os.path.exists(args.filename)
	print(args.filename[0], args.lines)
	return args.filename[0], args.lines

def readfile(filename):
	f = open(filename, 'r')  # 'r' = read
	linesRaw = f.read()

	lines = re.sub(r'(\W+)', lambda x: ' '+x.group(0)+' ', linesRaw).split() # separate punctuation
	lines = [i.lower() for i in lines] #force all strings to be lowercase
	lines = [x for x in lines if len(x)>4] #words longer than 4 characters
	f.close()
	return lines

def getuniquewords(lines):
	values, counts = np.unique(lines, return_counts=True)
	return values, counts

def main():
	# Ask for filename from user
	filename, numlines = getfilename()
	# Check if file exists
	try:
		lines = readfile(filename)
	except FileNotFoundError:
		print("File not found, please check file!")
		exit()
		# Cant find the file so exit the code

	# Sort the words by their frequency in the file
	values, counts = getuniquewords(lines)
	sortedValuesCounts = [x for x in sorted(zip(counts,values),reverse=True)]

	# print out words in descending order of frequency
	print('Word    Usage')
	for i in sortedValuesCounts[0:numlines]:
		print(f"{i[1]}	{i[0]}")
	pass


if __name__ == "__main__":
	main()
