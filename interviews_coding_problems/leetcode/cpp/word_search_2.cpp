/*
 * 212. Word Search II
 * Given a 2D board and a list of words from the dictionary, find all words in the board.  
 * Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
 * are those horizontally or vertically neighboring. The same letter cell may not be used more 
 * than once in a word.
 */

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Trie {
  public:
    map<char, Trie> children;
    bool finishes;
    int word_i;

    void insert(string& s, int i, int next) {
      if (next == s.size()) {
        finishes = true;
        word_i = i;
      } else {
        children[s[next]].insert(s, i, next+1);
      }
    }
};

int row_inc[] = {-1, 0, 1, 0};
int col_inc[] = {0, 1, 0, -1};

class WordSearch {
  public:
    Trie populate(vector<string>& words) {
      Trie t;
      for (int i = 0; i < words.size(); ++i) t.insert(words[i], i, 0);

      return t;    
    }

    bool is_valid(int row, int col, vector<vector<char> >& board) {
      return row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && board[row][col] != '*';
    }

    void dfs(int row, int col, Trie& t, vector<string>& found, const vector<string>& words, vector<vector<char> >& board) {
      if (t.finishes) found.push_back(words[t.word_i]);

      for (int i = 0; i < 4; ++i) {
        int moved_row = row+row_inc[i];
        int moved_col = col+col_inc[i];
        if (!is_valid(moved_row, moved_col, board)) continue;
        char moved_char = board[moved_row][moved_col];
        if (t.children.count(moved_char) > 0) {
          board[moved_row][moved_col] = '*';
          dfs(moved_row, moved_col, t.children[moved_char], found, words, board);
          board[moved_row][moved_col] = moved_char;
        }
      }        
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
      vector<string> found;
      Trie t = populate(words);
      int rows = board.size();
      if (rows == 0) return found;
      int cols = board[0].size();
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          if (t.children.count(board[i][j]) > 0) {
            char c = board[i][j];
            board[i][j] = '*';
            dfs(i, j, t.children[c], found, words, board);
            board[i][j] = c;
          }
        }
      }

      sort(found.begin(), found.end());
      auto it = unique(found.begin(), found.end());
      found.resize(distance(found.begin(), it));

      return found;
    }
};
