#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  int lecture_word_number, language_word_number;
  cin >> lecture_word_number >> language_word_number;

  map<string, string> dictionary;
  string l1_word, l2_word;
  for (int i = 0; i < language_word_number; ++i) {
    cin >> l1_word >> l2_word;
    if (l2_word.length() < l1_word.length()) {
      dictionary[l1_word] = l2_word;
    } else {
      dictionary[l1_word] = l1_word;
    }
  }

  string lecture_word;
  for (int i = 0; i < lecture_word_number; ++i) {
    cin >> lecture_word;
    cout << dictionary[lecture_word];
    if (i < lecture_word_number-1) {
      cout << " ";
    }
  }

  cout << endl;

  return 0;
}

