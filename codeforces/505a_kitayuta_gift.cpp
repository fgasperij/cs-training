#include <iostream>

using namespace std;

bool is_palindrome(string word)
{
  if (word.length() == 1 || word.length() == 0) {
    return true;
  }
  bool is_palindrome = true; 
  int left = 0;
  int right = word.length()-1;
  while(left < right && is_palindrome) {
    is_palindrome = (word[left] == word[right]);
    ++left; --right;
  }

  return is_palindrome;
}

// index position after it should be inserted
bool can_convert_palindrome(string word, int &index, char &letter)
{
  int left = 0;
  int right = word.length()-1;
  while(left < right) {
    if (word[left] != word[right]) {
      if (is_palindrome(word.substr(left, right-left))) {
        letter = word[right];
        index = left-1;
        return true;
      } else if(is_palindrome(word.substr(left+1, right-left))) {
        letter = word[left];
        index = right;
        return true;
      } else {
        return false;
      }
    }
    ++left; --right;
  }

  return false;
}

int main()
{
  string word;
  cin >> word;

  int index;
  char letter;
  if (is_palindrome(word)) {
    int middle = word.length()/2;
    if (word.length() % 2 == 0) {
      cout << word.substr(0, middle) << "d" << word.substr(middle) << endl;
    } else {
      cout << word.substr(0, middle+1) << word.substr(middle) << endl;
    }
  } else if (can_convert_palindrome(word, index, letter)) {
    if (index < 0) {
      cout << letter << word << endl;
    } else {
      cout << word.substr(0, index+1) << letter << word.substr(index+1) << endl;
    }
  } else {
    cout << "NA" << endl;
  }

  return 0;
}
