/*
 * 329. Longest Increasing Path in a Matrix
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or 
 * move outside of the boundary (i.e. wrap-around is not allowed).
 **/

#include <vector>
#include <algorithm>

using namespace std;

int bt(const vector<vector<int> >& m, vector<vector<int> >& dp, int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];

  int max_length = 1;
  int incr[4] = {-1, 0, 0, 1};
  int incc[4] = {0, 1, -1, 0};
  for (int k = 0; k < 4; ++k) {
    int ni = incr[k]+i;
    int nj = incc[k]+j;
    bool in_bounds = ni >= 0 && nj >= 0 && ni < m.size() && nj < m[0].size();
    if (in_bounds && m[ni][nj] > m[i][j]) 
      max_length = max(max_length, 1+bt(m, dp, ni, nj));
  }

  dp[i][j] = max_length;

  return max_length;
}

int longestIncreasingPath(vector<vector<int> >& matrix) {
  if (matrix.empty() || matrix[0].empty()) return 0;

  int rows = matrix.size(), cols = matrix[0].size();
  vector<vector<int> > dp(rows, vector<int> (cols, -1));

  int max_length = 1;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      max_length = max(max_length, bt(matrix, dp, i, j));

  return max_length;
}
