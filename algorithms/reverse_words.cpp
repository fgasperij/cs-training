#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverse_substring(string &sentence, int start, int end);
void reverse_words(string &sentence);

int main()
{
  string sentence("Hi there guys how are you doing");
  cout << "Original sentence: " << sentence << "\n";
  reverse_words(sentence);
  cout << "Reversed sentence: " << sentence << "\n";

  return 0;
}

void reverse_words(string &sentence)
{
  reverse_substring(sentence, 0, sentence.length());

  int word_start = 0;
  char space = ' ';
  for (int i = 0; i < sentence.length(); ++i) {
    if (sentence[i] == space) {
      reverse_substring(sentence, word_start, i);
      word_start = i + 1;
    }

    if (i == sentence.length() - 1) {
      reverse_substring(sentence, word_start, i+1);
      word_start = i + 1;
    }
  }
}

void reverse_substring(string &sentence, int start, int end)
{
  int middle = (end-start) / 2;
  int last = end - 1;
  for (int j = 0; j < middle; ++j) {
    swap(sentence[start+j], sentence[last-j]); 
  }
}
