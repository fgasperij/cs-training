#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
  unordered_set<char> included;
  int longest = 0, current = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (included.count(s[i])) {
      longest = max(longest, current);
      while (s[i-current] != s[i]) {
        included.erase(included.find(s[i-current]));
        --current;
      }
    } else {
      included.insert(s[i]);
      ++current;
    }
  }

  return max(longest, current);
}
