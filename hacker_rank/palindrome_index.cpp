#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_pal(string s) {
  int i = 0, last = s.length()-1, middle = s.length()/2;
  while (s[i] == s[last-i] && i < middle) ++i;

  return (i == middle);
}

int main() {
  int tests;
  cin >> tests;
  string s;
  while (tests--) {
    cin >> s;
    int i = 0, last = s.length()-1, middle = s.length()/2;
    while (s[i] == s[last-i] && i < middle) {
      ++i;
    }
    if (i == middle) {
      cout << -1;
    } else {
      cout << (is_pal(s.substr(i, last-i-i)) ? last-i : i);   
    }
    cout << '\n';
  }
  return 0;
}
