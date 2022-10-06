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

def sanitize_text(text: str):
    """
    Sanitize raw text to:
     - strip out punctuation from text such as .,?'"!() :
     - separate hyphenated words
     - standardize to lower case

    @param text: str - raw text to sanitize
    @return: str - sanitized text
    """
    special_characters = [".", ",", "?", "'", '"', "!", "(", ")", ":"]
    text = text.lower() # convert to lower case
    # Strip text of special characters such as uch as .,?'"!():
    for word in text:
        if word in special_characters:
            text = text.replace(word, "")

    text.strip('"') # removes double quotes

    text = text.replace("-", " ") # split hyphenated words
    return text

# count instances of words longer than 4 characters
def sorted_word_frequency(text: str):
    """
    Count instances of words longer than 4 characters and return as
    a sorted array of tuples in ascending order [(word, count), (word, count)]

    @param text: str - text to count words in
    @return: list - sorted array of tuples in ascending order [(word, count), (word, count)]
    """

    words_frequency_list = []
    string_list = text.split()
    unique_words = set(string_list) # set of unique words

    # Append words and frequency to list where words are longer than 4 characters
    for words in unique_words:
        if len(words) > 4:
            words_frequency_list.append((words, string_list.count(words)))

    return sorted( words_frequency_list, key=lambda t: t[1], reverse=True)

# validate if file exists and is a file
def validate_file(filename: str):
    """
    Validate if file exists and is a file

    @param filename: str - filename to validate
    @exception: OSError - if file does not exist or is not a file
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

def print_words(words: list):
    """
    Print out words and usage nicely in two evenly spaced columns Word and Usage

    @param words: list - list of tuples [(word, count), (word, count)]
    """
    print("Word".ljust(20), "Usage")
    print("----".ljust(20), "-----")
    for word in words:
        print(word[0].ljust(20), word[1])


def main():
    """Main method"""
    # Read in text file from user flags passed in
    filename = sys.argv[1] # get filename from user flags
    text = read_text_file(filename) # read in text file
    sanitized_text = sanitize_text(text) # sanitize raw text
    word_frequency = sorted_word_frequency(sanitized_text) # count word frequency
    print_words(word_frequency) # print words

if __name__ == "__main__":
    main()
