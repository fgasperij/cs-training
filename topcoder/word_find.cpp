#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct Movement {
  int original_row;
  int original_column;
  int current_row;
  int current_column;
  int row_inc;
  int col_inc;

  Movement(int orr, int oc, int cr, int cc, int ri, int ci) : original_row(orr), original_column(oc), current_row(cr), current_column(cc), row_inc(ri), col_inc(ci) {};
};

struct Trie {
  map<char, Trie> children;
  int word;

  Trie() { word = -1; };

  Trie(vector<string> words) {
    for (int i = 0; i < words.size(); ++i) insert(words[i], 0, i);
  }

  void insert(string s, int current, int pos) {
    if (current >= s.size()) {
      word = pos;
      return;
    }
    children[s[current]].insert(s, current+1, pos);
  }

  void find_words(const vector<string> &grid, Movement &m, vector<string> &coords) {
    if (word != -1 && coords[word].empty()) {
      stringstream ss;
      ss << m.original_row << " " << m.original_column;
      coords[word] = ss.str();
    }

    if (children.count(grid[m.current_row][m.current_column]) == 0) return;

    char c = grid[m.current_row][m.current_column];
    m.current_row += m.row_inc; 
    m.current_column += m.col_inc;
    if (m.current_row >= grid.size() && m.current_column >= grid[0].size()) return;
    children[c].find_words(grid, m, coords);
  }
};

class WordFind {
  public:
    vector<string> findWords(vector<string> grid, vector<string> word_list) {
      Trie t(word_list);
      
      vector<string> coords(word_list.size(), "");
      int rows = grid.size();
      int columns = grid[0].size();
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
          Movement down(i, j, i, j, 1, 0);
          t.find_words(grid, down, coords);

          Movement right(i, j, i, j, 0, 1);
          t.find_words(grid, right, coords);

          Movement diagonal(i, j, i, j, 1, 1);
          t.find_words(grid, diagonal, coords);
        }
      }

      return coords;
    }
};

int main() {
  WordFind wf;

  vector<string> grid;
  grid.push_back("TEST");
  grid.push_back("GOAT");
  grid.push_back("BOAT");

  vector<string> word_list;
  word_list.push_back("GOAT");
  word_list.push_back("BOAT");
  word_list.push_back("TEST");

  vector<string> coords = wf.findWords(grid, word_list);

  for (int i = 0; i < coords.size(); ++i) cout << "(" << coords[i] << ")\n";
}
