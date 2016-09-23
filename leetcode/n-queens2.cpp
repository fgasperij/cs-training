// https://leetcode.com/problems/n-queens-ii/
#include <iostream>
#include <vector>

using namespace std;

vector<int> queenRow;
vector<bool> usedRow;
int n;

bool canPutQueenIn(int row, int column) {
  if (usedRow[row])
    return false;
  // check with previous columns..
  for (int col = 0; col < column; col++)
    if (abs(queenRow[col] - row) == column - col)
      return false;
  return true;
}

int acumTotalNQueens(int column, int& acum) {
  if (column == n) {
    for (int i = 0; i < n; i++)
      cout << queenRow[i] << " ";
    cout << endl;
    acum++;
  }
  else {
    for (int row = 0; row < n; row++) {
      if (canPutQueenIn(row, column)) {
        queenRow[column] = row;
        usedRow[row] = true;
        acumTotalNQueens(column + 1, acum);
        usedRow[row] = false;
      }
    }

  }
}


int totalNQueens(int N) {
  n = N;
  queenRow = vector<int>(n);
  usedRow = vector<bool>(n, false);
  int acum = 0;
  acumTotalNQueens(0, acum);
  return acum;
}

int main() {
  cout << totalNQueens(4) << endl;
  return 0;
}
