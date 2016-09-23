/**
 * 279. Given a positive integer n, find the least number of perfect square 
 * numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 */

#include <vector>
#include <algorithm>

using namespace std;

int numSquares(int n) {
  if (n < 2) return 1;
  vector<int> v(n+1, n+1);
  v[0] = 0;
  for (int i = 0; i < n; ++i) {
    int s = 1, square;
    while (i+s*s <= n) {
      square = s*s;
      v[i+square] = min(v[i+square], 1+v[i]);
      ++s;
    }
  }

  return v[n];
}
