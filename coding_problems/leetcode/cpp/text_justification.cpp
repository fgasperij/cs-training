#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> justified;
  int word_i = 0;
  while (word_i < words.size()) {
    int letters = words[word_i].size();
    int base_spaces = 0;
    ++word_i;
    int words_in_line = 1;
    bool adding = true;
    while (word_i < words.size() && adding) {
      int word_adds = words[word_i].size() + 1;
      int filled = letters+base_spaces;
      if (filled + word_adds <= maxWidth) {
        ++words_in_line;
        ++base_spaces;
        letters += words[word_i].size();
        ++word_i;
      } else {
        adding = false;
      }
    }
    bool last_line = word_i == words.size();
    string line;
    if (last_line) {
      for (int i = word_i - words_in_line; i < word_i; ++i) {
        line += words[i];
        if (i < word_i-1) line += ' ';
      }
      while (line.size() < maxWidth) line += ' ';
      justified.push_back(line);
      continue;
    }
    if (words_in_line == 1) {
      line += words[word_i-1];
      while (line.size() < maxWidth) line += ' ';
      justified.push_back(line);
      continue;
    }
    int pads = maxWidth - (letters+base_spaces);
    int extra_pads = pads % (words_in_line-1);
    int spaces = (pads+base_spaces)/base_spaces;
    for (int i = word_i - words_in_line; i < word_i; ++i) {
      line += words[i];
      if (i < word_i-1) {
        int s = spaces;
        while (s--) line += ' ';
        if (extra_pads > 0) {
          line += ' ';
          --extra_pads;
        }
      }
    }
    justified.push_back(line);
  }

  return justified;
}
