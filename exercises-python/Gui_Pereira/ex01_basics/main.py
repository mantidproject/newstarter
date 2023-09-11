#!/usr/bin/env python3
import numpy as np
from pathlib import Path

def main():
    file_path = Path(__file__).parent.absolute() / 'holmes.txt'
    full_text = file_path.read_text()

    for c in '.,?"!():':    # Not very elegant
        full_text  = full_text.replace(f'{c}', '')

    full_text  = full_text.replace('-', ' ')     # Treat hyphenated words seperatly 
    full_text  = full_text.lower()        # Pass everything to lowercases 
    word_list = full_text.split()     # Split words seperated with any white space
    word_list = [w for w in word_list if len(w)>4]    # Consider words longer than 4 ch

    words, counts = np.unique(word_list, return_counts=True)    # Count ocurrences

    sorted_indices = np.argsort(-counts)
    for i, (w, c) in enumerate(zip(words[sorted_indices], counts[sorted_indices])):
        print(f'{w:10} : {c}')
        if i==30:break     # Print first 30 words 

if __name__ == "__main__":
	main()
