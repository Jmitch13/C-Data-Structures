# Project 5
## CSUF CPSC 131, Fall 2018

Use of a multimap to take the text of chapter 1, Harry Potter and the Sorcerer's Stone. 
The following four functions were implemented

void add_word(const std::string&, size_t);
adds a word to the multimap if it is not already present

size_t total_words() const;
returns the number of total words for the paragraph, page, and chapter

size_t total_words(size_t length) const;
returns the number of words at each size

void print(std::ostream&) const;
prints out all the values in the multimap

