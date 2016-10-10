#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct Cell {
  int r, c, dist;
  Cell(int r, int c, int d) : r(r), c(c), dist(d) {};
};

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<vector<Cell> > v(p);
  int t;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> t;
      v[t-1].push_back(Cell(i, j, (t == 1 ? i+j : numeric_limits<int>::max())));
    }
  }

  for (int i = 0; i < p-1; ++i)
    for (int j = 0; j < v[i].size(); ++j)
      for (int k = 0; k < v[i+1].size(); ++k)
        v[i+1][k].dist = min(v[i+1][k].dist, 
            abs(v[i+1][k].r-v[i][j].r)+abs(v[i+1][k].c-v[i][j].c)+v[i][j].dist);

  cout << v[p-1][0].dist << endl;

  return 0;
}
