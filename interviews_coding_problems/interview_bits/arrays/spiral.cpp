#include <iostream>
#include <vector>

using namespace std;

enum class Direction : char {RIGHT, DOWN, LEFT, UP};

vector<vector<int> > spiral_fsm(int n) {
  if (n < 0) throw "ArgumentError";

  int cr = 0, cc = 0, cloop = 1, n2 = n*n;
  vector<vector<int> > m(n, vector<int> (n));
  Direction dir = Direction::RIGHT;
  for (int i = 1; i < n2; ++i) {
    switch (dir) {
      case Direction::RIGHT:
        if (cc == n - cloop) {
          ++cr;
          dir = Direction::DOWN;
        } else {
          ++cc;
        }
        break;
      case Direction::DOWN:
        if (cr == n - cloop) {
          --cc;
          dir = Direction::LEFT;
        } else {
          ++cr;
        }
        break;
      case Direction::LEFT:
        if (cc == cloop - 1) {
          --cr;
          dir = Direction::UP;
        } else {
          --cc;
        }
        break;
      case Direction::UP:
        if (cr == cloop) {
          ++cc;
          dir = Direction::RIGHT;
          ++cloop;
        } else {
          --cr;
        }
        break;
      default:
        throw "InvalidDirection";
    }
  }

  return m;
}

vector<vector<int> > spiral_lines(int n) {
  if (n < 0) throw "ArgumentError";
  if (n == 0) return vector<vector<int> > ();

  vector<vector<int> > m(n, vector<int> (n, 1));
  int spi = 1, n2 = n * n, i = 0;
  while (spi < n2) {
    int last = (n-1)-i;
    int first = i;
    for (int j = first; j <= last; ++j) {
      m[first][j] = spi;
      ++spi;
    }
    for (int j = first+1; j < last; ++j) {
      m[j][last] = spi;
      ++spi;
    }
    for (int j = last; j > first; --j) {
      m[last][j] = spi;
      ++spi;
    }
    for (int j = last; j > first; --j) {
      m[j][first] = spi;
      ++spi;
    }

    ++i;
  }

  return m;
}

void print_matrix(const vector<vector<int> >& m) {
  int n = m.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << m[i][j];
      if (j < n-1) cout << " ";
    }
    cout << '\n';
  }
}

int main() {

  return 0;
}
