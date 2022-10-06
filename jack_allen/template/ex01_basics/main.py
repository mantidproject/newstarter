#!/usr/bin/env python3

"""
A script to answer the solution for Exercise 1 which is to create a command line program:

Write a command line program that will:

1). Take a filename of an ascii file as an argument (you can use the example file here)

2). Load that ascii file.

3). Count the number of occurrences of unique words (longer than 4 characters and
split hyphenated words, treating each part as different words).
It should be case and punctuation insensitive.
You only need to consider the following punctuation characters .,?'"!():
(hint: you will need a backslash escape character for the double-quote)

4). Consider handling of common error cases, such as the wrong file name specified. R
eturn error and status information to the user of the command line tool.

5). Print the results to screen showing the unique words and the number of
uses in descending order of usage, e.g.
"""

import sys
import os

# Method to read a text file and return as a string
def read_text_file(filename: str):
    """
    Read in a text file and return a string.
    Reading in the file as a string will allow us to manipulate the text
    (choosing not to stream assuming the file is small)))
    """
    # check file exsists and return error if not
    validate_file(filename)

    # open file and read in contents
    try:
        with open(filename, "r", encoding="UTF-8") as text_file:
            text = text_file.read()
    except OSError as fileerror:
        print(f"Error reading file {filename}: {fileerror}")
        sys.exit(1)

    return text


# Split hyphenated strings
def split_hyphenated_strings(hyphenated_word:str):
    """
    Split hyphenated words into two seperate words and return as seperate string values
    """
    pass


# strip out punctuation from text such as .,?'"!():
def strip_punctuation(text: str):
    """
    Strip out punctuation from text
    """
    pass

# count instances of words longer than 4 characters
def count_words(text: str):
    """
    Count instances of words longer than 4 characters
    """
    pass


# validate if file exists and is a file
def validate_file(filename: str):
    """
    Validate if file exists and is a file
    """

    # check file exists
    if not os.path.exists(filename):
        print(f"File {filename} does not exist")
        sys.exit(1)

    # check file is a file
    if not os.path.isfile(filename):
        print(f"{filename} is not a file")
        sys.exit(1)

    # check file is a text file
    if not filename.endswith(".txt"):
        print(f"{filename} is not a text file")
        sys.exit(1)

# sort words by usage in descending order
def sort_words_by_usage(words: dict):
    """
    Sort words by usage High to Low
    """
    pass

# print out words and usage
def print_words(words: dict):
    """
    Print out words and usage
    """
    pass

def main():
    """Main method"""
    # read in text file from user flags passed in
    filename = sys.argv[1]
    text = read_text_file(filename)
    print(text)

if __name__ == "__main__":
    main()
