#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> back_table(const string& s) {
  // back[i] == position after the end of the longest border of s[..(i-1)]
  // back[i] == length of the longest border of s[..(i-1)]
  vector<int> back(s.size()+1, -1);
  // i == position of the last character of the current string
  // j == length of the longest border of s[..(i-1)]
  int i = 0, j = -1, n = s.size();
  while (i < n) {
    // find the longest prefix which is a border and whose next character
    // is s[i], the last one of the new string, s[..i]
    while(j >= 0 && s[i] != s[j]) j = back[j];
    ++i; ++j;
    back[i] = j;
  }

  return back;
}

vector<int> kmp(const string& pattern, const string& text) {
  vector<int> back = back_table(pattern);
  vector<int> ocurrences;
  int ip = 0, it = 0, tn = text.size(), pn = pattern.size();
  while (it < tn) {
    while (ip >= 0 && pattern[ip] != text[it]) ip = back[ip];
    ++it; ++ip;
    if (ip == pn) {
      ocurrences.push_back(it-pn);
      ip = back[ip];
    }
  }

  return ocurrences;
}

int main() {
  string pattern("agu");
  string text("agua bonita con agujas en agujeros");
  vector<int> ocs = kmp(pattern, text);
  cout << pattern << " \n" << text << endl;
  for (int i = 0; i < ocs.size(); ++i) cout << ocs[i] << " ";
  cout << endl;

  return 0;
}
