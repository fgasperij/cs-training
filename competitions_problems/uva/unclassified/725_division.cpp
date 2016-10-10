/*
 * started: 19:06
 * ac: 20:00
 * */

#include <iostream>
#include <iomanip>

using namespace std;

bool valid_pair(int i, int j) {
  int bi = i, bj = j;
  if (i <= 9999 && j <= 9999) return false;
  bool used[10] = {};
  while (i) {
    if (used[i%10]) return false;
    used[i%10] = true;
    i /= 10;
  }
  while (j) {
    if (used[j%10]) return false;
    used[j%10] = true;
    j /= 10;
  }

  if ((bi <= 9999 || bj <= 9999) && used[0]) return false;

  return true;
}

int main() {
  cout << setfill('0');
  int n;
  cin >> n;
  bool first = true;
  while (n) {
    if (!first) cout << '\n';
    first = false;
    bool exists = false;
    for (int den = 1234; den <= 98765 && n*den <= 98765; ++den) {
      int num = n*den;
      if (valid_pair(den, num)) {
        cout << setw(5) << num << " / " << setw(5) << den << " = " << n << '\n';
        exists = true;
      }
    }
    if (!exists) cout << "There are no solutions for " << n << ".\n";

    cin >> n;
  }
}
