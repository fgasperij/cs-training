#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int n, m;
  cin >> n >> m;

  vector<int> row_directions(n, 0);
  vector<int> column_directions(m, 0);
  getchar();
  for (int i = 0; i < n; ++i) {
    if (getchar() == '>') {
      row_directions[i] = 1;
    } else {
      row_directions[i] = -1;
    }
  }
  getchar();
  for (int i = 0; i < m; ++i) {
    if (getchar() == 'v') {
      column_directions[i] = 1;
    } else {
      column_directions[i] = -1;
    }
  }
  if (n == 1 && m == 1) {
    cout << "YES" << endl;
  } else if (n >= 2 && m >=2) {
    bool clockwise = row_directions[0] == 1 && column_directions[m-1] == 1 &&
      row_directions[n-1] == -1 && column_directions[0] == -1;
    bool anticlockwise = row_directions[0] == -1 && column_directions[m-1] == -1 &&
      row_directions[n-1] == 1 && column_directions[0] == 1;
    if (clockwise || anticlockwise) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
