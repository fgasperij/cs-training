#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int max_edge(const string& s) {
  if (s.empty()) return 0;
  vector<int> back(s.size()+1, -1);
  int i = 0, j = -1, n = back.size();
  while (i < n) {
    while (j >= 0 && s[i] != s[j]) j = back[j];
    ++i; ++j;
    back[i] = j;
  }

  int res = back[n-1], max_size = s.size()/2;
  while (res > max_size) res = back[res];

  return res;
}

string shortestPalindrome(const string& s) {
  string rev_s(s);
  reverse(rev_s.begin(), rev_s.end());
  int max_prefix = min(max_edge(s+rev_s), (int)s.size());
  string pre(s.substr(max_prefix));
  reverse(pre.begin(), pre.end());
  return pre+s;
}

int main() {
  /* string s("asdffdsautyr"); */
  /* string s(""); */
  string s("aabba");
  cout << shortestPalindrome(s) << endl;

  return 0;
}
