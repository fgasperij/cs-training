#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A = 5;
  int spi = 1;
  vector<vector<int> > spiral(A, vector<int> (A,1));
  for (int i = 0; i < ((A-1)/2)+1; ++i) {
    int last = (A-1)-i;
    int first = i;
    for (int j = first; j <= last; ++j) {
        spiral[first][j] = spi;
        ++spi;
    }
    for (int j = first+1; j < last; ++j) {
        spiral[j][last] = spi;
        ++spi;
    }
    for (int j = last; j > first; --j) {
        spiral[last][j] = spi;
        ++spi;
    }
    for (int j = last; j > first; --j) {
        spiral[j][first] = spi;
        ++spi;
    }
  }

  for (int i = 0; i < A; ++i) {
    for (int j = 0; j < A; ++j) {
      cout << " " << spiral[i][j];
    }
    cout << '\n';
  }

  return 0;
  
}
