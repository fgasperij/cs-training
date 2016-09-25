/*
  Given an index k (0 based), return the kth row of the Pascal’s triangle.

  ## Questions

  - what if k is negative?
  - can we assume that k fits into memory?
  - what if k is too big? we should watch out for overflows
  - how does the values of the triangle grow?
*/

#include <vector>
#include <iostream>

using namespace std;

vector<unsigned long long> pascal_row(int k) {
  if (k < 0 || k > 100) throw "ArgumentError";

  vector<unsigned long long> r(k+1, 1);
  for (int i = 2; i <= k; ++i) {
    for (int j = i-1; j > 0; --j) {
      r[j] += r[j-1];
    }
  }

  return r;
}

int main() {
  int k;
  cin >> k;

  vector<unsigned long long> r = pascal_row(k);

  for (auto e : r) cout << e << " ";

  cout << endl;

  return 0;
}
