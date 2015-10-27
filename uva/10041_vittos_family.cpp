/*
 * started: 14:00
 * ac: 14:25
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int r;
    cin >> r;
    vector<int> ns(r);
    for (int i = 0; i < r; ++i) {
      cin >> ns[i];
    }

    sort(ns.begin(), ns.end());

    int median = ns[r/2];
    int sum = 0;
    for (int i = 0; i < r; ++i) {
      sum += abs(ns[i]-median);
    }

    cout << sum << '\n';
  }

  return 0;
}
