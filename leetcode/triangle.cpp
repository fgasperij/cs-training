/**
 * 120. Given a triangle, find the minimum path sum from top to bottom. Each step you may move to
 * adjacent numbers on the row below:
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 */

#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
  if (triangle.empty()) return 0;

  int rows = triangle.size();
  vector<int> v(rows, 0);

  if (rows == 1) return triangle[0][0];
  v[0] = triangle[0][0] + triangle[1][0];
  v[1] = triangle[0][0] + triangle[1][1];

  for (int i = 2; i < rows; ++i) {
    v[i] = triangle[i][i] + v[i-1];
    for(int j = i-1; j > 0; --j)
      v[j] = triangle[i][j] + min(v[j], v[j-1]);
    v[0] += triangle[i][0];
  }

  return *min_element(v.begin(), v.end());
}

int minimumTotal2(vector<vector<int> >& triangle)
{
  int rows = triangle.size();
  vector<int> v(triangle[rows-1]);
  for (int r = rows-1; r > 0; --r)
    for (int c = 0; c < r; ++c)
      v[c] = triangle[r-1][c] + min(v[c], v[c+1]);

  return v[0];
}
