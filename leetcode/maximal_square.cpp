#include <vector>
#include <algorithm>

using namespace std;

struct ConsecutiveOnes {
  int left;
  int up;
  int max_side;
};

int maximalSquare(vector<vector<char> >& matrix) {
  int rows = matrix.size();
  if (rows == 0) return 0;
  int cols = matrix[0].size();
  if (cols == 0) return 0;

  vector<vector<ConsecutiveOnes> > vvi(rows, vector<ConsecutiveOnes> (cols));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      vvi[i][j].max_side = matrix[i][j] == '1' ? 1 : 0;
      if (i == 0) {
        vvi[i][j].up = 0;
      } else {
        vvi[i][j].up = matrix[i-1][j] == '0' ? 0 : vvi[i-1][j].up+1;
      }
      if (j == 0) {
        vvi[i][j].left = 0;
      } else {
        vvi[i][j].left = matrix[i][j-1] == '0' ? 0 : vvi[i-1][j].left+1;
      }
    }
  }
  int maxs = 0;
  for (int i = 1; i < rows; ++i) {
    for (int j = 1; j < cols; ++j) {
      if (matrix[i][j] == '1') {
        vvi[i][j].max_side = min(vvi[i-1][j-1].max_side, min(vvi[i][j].up, vvi[i][j].left));
        maxs = max(vvi[i][j].max_side, maxs);
      }
    }
  }

  return maxs;
}
