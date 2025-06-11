/*
  Given numRows, generate the first numRows of Pascal’s triangle.

  Questions
  - what if k rows do not fit into memory?
  you should calculate that and throw an exception. This case is improbable since the primitive
  data types will upper bound k tighter. Unless a different data type is used this shouldn't
  be considered. It's more easy than that. Usually vector will give some hint or malloc will fail.
  - what if k is negative?
  throw an exception.
  - is it 0 or 1 based?
  assume is 0 based.
  - what if the value of the max number of row k is not representable with ull?
  throw an exception.

  Optimizations
  - allocate all the space at the beginning since it can be calculated.

  Test cases
  - k < 0 || k > overflow --> throw exception
  - k > memory size
  - k > representable

*/

#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

vector<vector<ull> > k_rows(int k) {
  if (k < 0 || k > 100) throw "ArgumentError";

  vector<vector<ull> > rows;
  for (int r = 0; r < k; ++r) {
    vector<ull> row(r+1, 1);
    for (int i = 1; i < r; ++i) {
      row[i] = rows[r-1][i] + rows[r-1][i-1];
    }
    rows.push_back(row);
  }

  return rows;
}

int main() {
  int k;
  cin >> k;
  vector<vector<ull> > rows = k_rows(k);

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < i+1; ++j) {
      cout << rows[i][j];
      if (j < i)  cout << " ";
    }
    cout << endl;
  }

  return 0;
}
