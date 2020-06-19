#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>      /* std::transform */
#include <string>         /* not needed for Mac OSX */


class TextAnalysis { 
public:
  TextAnalysis() = default;  
  void add_word(const std::string&, size_t); // IMPLEMENT BELOW
  size_t countWord(const std::string&); // IMPLEMENT BELOW
  size_t countTwoWords(const std::string&, const std::string&); // IMPLEMENT BELOW
  
  void read_text(std::istream&, const std::string&); // ALREADY DONE
  
private:  
  std::unordered_map<std::string, std::vector<size_t> > wordtable; // hash table with key=word and value=vector of page numbers
};

// ALREADY DONE: BREAK A LINE INTO A LIST OF WORDS
// Courtesy of Martin Broadhurst -- http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
template <class Container>
void split(const std::string& str, Container& cont, const std::string& delims = " ") {
  std::size_t curr, prev = 0;
  curr = str.find_first_of(delims);
  
  while (curr != std::string::npos) {                   // largest possible unsigned number
    cont.push_back(str.substr(prev, curr - prev));
    prev = curr + 1;
    curr = str.find_first_of(delims, prev);
  }
  
  cont.push_back(str.substr(prev, curr - prev));
}

// ALREADY DONE: READ FROM A TEXT FILE LINE BY LINE
void TextAnalysis::read_text(std::istream& in, const std::string& ignore) {
  std::string line;
  
  for (size_t i = 1; getline(in, line, '\n'); i++) {
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    
    typedef std::list<std::string> container;
    container words;                          // split into container, dump ignore chars
    split<container>(line, words, ignore);
    
    typename container::const_iterator cit;
    for (cit = words.cbegin(); cit != words.cend(); ++cit) { add_word(*cit, i); }
  }
}

void TextAnalysis::add_word(const std::string& word, size_t line) {
    
    std::unordered_map<std::string, std::vector<size_t>> :: iterator it;
    it = wordtable.find(word);
    //Iterator checks to see if the word has been implemented yet
    if (it != wordtable.end()) {
        //Adds the value
        wordtable[word].push_back(line);
    } else {
        //Creates a vector to be added to the word
        wordtable[word] = std::vector<size_t>();
        //Adds a new value to the vector
        wordtable[word].push_back(line);
    }
}

size_t TextAnalysis::countWord(const std::string& word) {
    //Counts all the words within the word table
    return wordtable[word].size();
}

size_t TextAnalysis::countTwoWords(const std::string& word1, const std::string& word2) {
    size_t count = 0;
    int number = 0;
    int lastNum = 0;
    //For loop to go through all the values in the loop
    for (int i = 0; i < wordtable[word1].size(); i++)
    {
        //Checks to see if a value from word1 equals a value from word2
        number = wordtable[word1][i];
        //Checks previous value in the vector
        lastNum = wordtable[word1][i-1];
        //Increments the count if the duplicate was not already counted
        if(std::find(wordtable[word2].begin(), wordtable[word2].end(),number) != wordtable[word2].end())
        {
            if (lastNum != number)
            {
                count++;
            }
        }
    }
    //Returns the value of the two words
    return count;
}


