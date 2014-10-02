#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  std::vector<std::string> sentences;
  int maximum_length = 0;

  while (!std::cin.eof()) {
    std::string sentence;
    getline(std::cin, sentence);
    sentences.push_back(sentence);
    if (sentence.length() > maximum_length) {
      maximum_length = sentence.length();
    }
  }

  for (int j = 0; j < maximum_length; j++) {
    for (int i = sentences.size()-1; i >= 0; i--) {
      if (j < sentences[i].length()) {
        std::cout << sentences[i][j];
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }

  return 0;
    
}
