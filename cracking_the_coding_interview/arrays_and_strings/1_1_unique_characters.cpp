#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool only_uniques_sort(string s) {
  sort(s.begin(), s.end());

  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == s[i-1]) return false;
  }

  return true;
};

bool only_uniques_vector(string s) {
  vector<bool> seen(100, false);
  for (int i = 0; i < s.length(); ++i) {
    int id = ((int)s[i]) % 100;
    if (seen[id]) return false;
    seen[id] = true;
  }

  return true;
} ;

bool only_uniques_set(string s) {
  unordered_set<char> seen;
  for (int i = 0; i < s.length(); ++i) {
    if (seen.count(s[i]) > 0) return false;
    seen.insert(s[i]);
  }

  return true;
};

bool only_uniques_trivial(string s) {
  for (int i = 0; i < s.length(); ++i) {
    for (int j = 0; j < s.length(); ++j) {
      if (i != j && s[i] == s[j]) return false;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {

  if (argc > 3) {
    cout << "What are you doing, pal?\n";
    return 0;
  }


  char *strategy = argv[1];
  string input(argv[2]);
  cout << "Strategy: " << strategy << " input: " << input << '\n';

  bool uniques;
  switch(strategy[0]) {
    // sort
    case 's':
      uniques = only_uniques_sort(input);
      break;
    // vector
    case 'v':
      uniques = only_uniques_vector(input);
      break;
    // unordered_set
    case 'u':
      uniques = only_uniques_set(input);
      break;
    // trivial
    default:
      uniques = only_uniques_trivial(input);
      break;
  }

  cout << (uniques ? "ALL UNIQUES" : "DUPLICATE FOUND") << '\n';

  return 0;
}
