#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
  if (s.empty() || words.empty()) return vector<int>();
  unordered_multiset<string> all_words;
  for (string w : words) all_words.insert(w);

  vector<int> indexes;
  int k = words[0].size();
  for (int i = 0; i < k; ++i) {
    unordered_multiset<string> available_words(all_words);
    int l = i, r = i, words_left = words.size();
    string next;
    while (r+k <= s.size()) {
      next = s.substr(r, k);
      unordered_multiset<string>::iterator it_next = available_words.find(next);
      if (it_next != available_words.end()) {
        if (words_left == 1) {
          indexes.push_back(l);
          available_words.insert(s.substr(l, k));
          ++words_left;
          l += k;
        }
        available_words.erase(it_next);
        r += k;
        --words_left;
      } else {
        if (l == r) {
          r += k;
        } else {
          available_words.insert(s.substr(l, k));
          ++words_left;
        }
        l += k;
      }
    }
  }

  return indexes;
}
