#!/usr/bin/env python3

"""
A script following function programming paradigm to answer the solution
for Exercise 1 which is to create a command line program:

Write a command line program that will:
    1). Take a filename of an ascii file as an argument (you can use the example file here)
    2). Load that ascii file.
    3). Count the number of occurrences of unique words (longer than 4 characters and
    split hyphenated words, treating each part as different words).
    It should be case and punctuation insensitive.
    You only need to consider the following punctuation characters .,?'"!():
    (hint: you will need a backslash escape character for the double-quote)
    4). Consider handling of common error cases, such as the wrong file name specified. R
    return error and status information to the user of the command line tool.
    5). Print the results to screen showing the unique words and the number of
    uses in descending order of usage, e.g.

Script usage:
The text file used as input must be in the same directory as the script to work

Run the following command in your terminal to run the script: `python main.py text.txt`
"""

import sys
import os

from collections import Counter

# Method to read a text file and return as a string
def read_text_file(filename: str):
    """
    Read in a text file and return a string.
    Reading in the file as a string will allow us to manipulate the text
    (choosing not to stream assuming the file is small)))

    @param filename: str - filename to read in
    @return: str - The raw pre-processed text from the file
    """
    validate_file(filename)  # check file exists and return error if not

    # open file and read in contents
    try:
        with open(filename, "r", encoding="UTF-8") as text_file:
            text = text_file.read()
    except OSError as file_error:
        print(f"Error reading file {filename}: {file_error}")
        sys.exit(1)

    return text

def sanitize_text(text: str) -> str:
    """
    Sanitize raw text to:
     - strip out punctuation from text such as .,?'"!() :
     - separate hyphenated words
     - standardize to lower case

    @param text: str - raw text to sanitize
    @return: str - sanitized text
    """
    special_characters = [".", ",", "?", "'", '"', "!", "(", ")", ":"]
    # # Strip text of special characters such as uch as .,?'"!():
    for word in text.lower():
        if word in special_characters:
            text = text.replace(word, "")

    text.strip('"') # Removes double quotes

    return text.replace("-", " ") # Split hyphenated words

def sorted_word_frequency(text: str) -> list:
    """
    Count instances of words longer than 4 characters and return as
    a sorted array of tuples in ascending order [(word, count), (word, count)]

    @param text: str - text to count words in
    @return: list - sorted array of tuples in ascending order [(word, count), (word, count)]
    """

    frequency = Counter(text.split()) # Count instances of words

    # Sort by value in ascending order
    return sorted(frequency.items(), key=lambda pair: pair[1], reverse=True)

def validate_file(filename: str) -> bool:
    """
    Validate if file exists and is a file

    @param filename: str - filename to validate
    @exception: OSError - if file does not exist or is not a file
    """

    # Check file exists
    if not os.path.exists(filename):
        print(f"File {filename} does not exist")
        sys.exit(1)

    # Check file is a file
    if not os.path.isfile(filename):
        print(f"{filename} is not a file")
        sys.exit(1)

    # Check file is a text file
    if not filename.endswith(".txt"):
        print(f"{filename} is not a text file")
        sys.exit(1)

def print_words(words: list) -> None:
    """
    Print out words and usage nicely in two evenly spaced columns Word and Usage

    @param words: list - sorted list of tuples [(word, count), (word, count)]
    """
    print("Word".ljust(20), "Usage")
    print("----".ljust(20), "-----")
    for word in words:
        print(word[0].ljust(20), word[1])

def main():
    """Main method"""
    # Read in text file from user flags passed in
    filename = sys.argv[1] # Get filename from user flags
    text = read_text_file(filename) # Read in text file
    sanitized_text = sanitize_text(text) # Sanitize raw text
    word_frequency = sorted_word_frequency(sanitized_text) # Count word frequency
    print_words(word_frequency) # Print words and usage

if __name__ == "__main__":
    main()
