#!/usr/bin/env python3

from pathlib import Path
import sys


def main():
    # file_path = Path(__file__).parent.absolute() / 'holmes.txt'
    file_path = Path(sys.argv[1])
    full_text = file_path.read_text()

    for c in '.,?"!():':    # Not very elegant
        full_text  = full_text.replace(f'{c}', '')

    full_text  = full_text.replace('-', ' ')     # Treat hyphenated words seperatly 
    full_text  = full_text.replace("'", ' ')     # Treat hyphenated words seperatly 
    full_text  = full_text.lower()        # Pass everything to lowercases 
    word_list = full_text.split()     # Split words seperated with any white space
    word_list = [w for w in word_list if len(w)>4]    # Consider words longer than 4 ch

    # Count words
    word_count = {}
    for word in word_list:
        try:
            word_count[word] += 1
        except KeyError:
            word_count[word] = 1

    # Sort in decreasing order
    word_count = dict(sorted(word_count.items(), key=lambda x : -x[1]))

    print(f'{"Word":10} Usage')
    for i, word in enumerate(word_count):
        print(f'{word:10} {word_count[word]}')
        if i==30: break


if __name__ == "__main__":
	main()
