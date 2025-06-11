#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Naive version (Time Limit Exceeded)
// O(n^2 * l)

bool isSumPalindrome(string& s1, string& s2) {
  string s = s1 + s2;
  int n = s.size();
  for (int i = 0; i < n / 2; i++)
    if (s[i] != s[n - 1 - i])
      return false;
  return true;
}

vector<vector<int> > palindromePairs(vector<string>& words) {
  vector<vector<int> > res;
  for (int i = 0; i < words.size(); i++) {
    for (int j = 0; j < words.size(); j++) {
      if (i != j && isSumPalindrome(words[i], words[j]))
        res.push_back(vector<int> {i, j});
    }
  }
  return res;
}

// - armo un trie para las cadenas inversas

// multimap of string -> ints
struct Trie {
  unordered_map<char, Trie> children;
  list<int> straight;
  list<int> revs;

  void insert(const char* s, int value, bool is_straight) {
    if (*s == '\0') {
      if (is_straight) {
        straight.push_back(value);
      } else {
        revs.push_back(value);
      }
    } else {
      children[*s].insert(s + 1, value, is_straight);
    }
  }
};

Trie populate(vector<string>& words) {
  Trie res;
  for (int i=0; i <int(words.size()); i++) {
    string rev = words[i];
    res.insert(rev.c_str(), i, true);
    reverse(rev.begin(), rev.end());
    res.insert(rev.c_str(), i, false);
  }
  return res;
}

bool isPalindromeFrom(string s, int k) {
  int n = s.size();
  for (int i = k; i < k + (n - k)/2; i++) {
    if (s[i] != s[n - 1 - (k-i)])
      return false;
  }
  return true;
}

void findSumPalindrome(Trie* t, int currIndex, string& currentWord, vector<vector<int> >& appendTo, bool is_straight) {
  int n = currentWord.size();
  for (int i=0; i <= n; i++) {
    if (((!is_straight && !t->straight.empty())  || (is_straight && !t->revs.empty()))
        && isPalindromeFrom(currentWord, i)) {
      list<int>& indexes = is_straight ? t->revs : t->straight;
      for (int j : indexes)
        if (currIndex != j) {
          if (is_straight) {
            appendTo.push_back(vector<int>{currIndex, j});
          } else {
            appendTo.push_back(vector<int>{j, currIndex});
          }
        }
    }
    if (i >= n || t->children.find(currentWord[i]) == t->children.end()) return;
    t = &(t->children[currentWord[i]]);
  }
}

vector<vector<int> > findAllSumPalindromes(vector<string> words) {
  Trie tR = populate(words);
  vector<vector<int> > res;
  for (int i = 0; i < int(words.size()); i++) {
    findSumPalindrome(&tR, i, words[i], res, true); 
    string rev = words[i];
    reverse(rev.begin(), rev.end());
    findSumPalindrome(&tR, i, rev, res, false); 
  }
  return res;
}

int main() {
  vector<string> v{{"bat", "tab", "cat", "atatab"}};
  vector<vector<int> > pairs = findAllSumPalindromes(v);
  /* vector<vector<int> > pairs = palindromePairs(v); */
  for (auto palindrome_pair : pairs)
    cout << palindrome_pair[0] << ", " << palindrome_pair[1] << endl;
  return 0;
}
