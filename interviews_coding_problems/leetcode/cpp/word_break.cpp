/**
 * 139. Given a string s and a dictionary of words dict, determine if s can be segmented into a
 * space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreakFrom(string& s, int i, unordered_set<string>& dict, vector<int>& v) {
  if (i == s.size()) return true;
  if (v[i] != 0) return v[i] == 1;
  for (int j = i; j < s.size(); ++j) {
    if (dict.count(s.substr(i, j-i+1)) && wordBreakFrom(s, j+1, dict, v)) {
      v[i] = 1;
      return true;
    }
  }

  v[i] = -1;
  return false;
}

bool wordBreakRecursive(string s, unordered_set<string>& wordDict) {
  vector<int> v(s.size(), 0);
  return wordBreakFrom(s, 0, wordDict, v);
}

bool wordBreakIterative(string s, unordered_set<string>& wordDict) {
  vector<bool> v(s.size()+1, false);
  v[0] = true;
  for (int i = 1; i <= s.size(); ++i) {
    int j = 0;
    while (!v[i] && j < i) {
      v[i] = v[j] && wordDict.count(s.substr(j, i-j)) > 0;
      ++j;
    }
  }

  return v[s.size()];
}
