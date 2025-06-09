/*
 * 73. Set matrix to zeroes
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * */

#include <vector>
#include <algorithm>

using namespace std;

void set_zeroes(vector<vector<int> >& matrix) {
  bool first_column_zero = false;
  if (matrix.empty()) return;
  int rows = matrix.size();
  if (matrix[0].empty()) return;
  int cols = matrix[0].size();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        if (j == 0) {
          first_column_zero = true;
        } else {
          matrix[0][j] = 0;
        }
      }
    }
  }
  for (int i = 1; i < rows; ++i) {
    if (matrix[i][0] == 0)
      fill(matrix[i].begin()+1, matrix[i].end(), 0);
  }
  for (int j = 1; j < cols; ++j) {
    if (matrix[0][j] == 0)
      for (int i = 0; i < rows; ++i) matrix[i][j] = 0;
  }

  if (matrix[0][0] == 0) fill(matrix[0].begin(), matrix[0].end(), 0);

  if (first_column_zero)
    for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
}
