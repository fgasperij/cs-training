/*
 * started: 10:46
 * ac: 10:55
 * */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    int sum = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (v[j] <= v[i]) ++sum;
      }
    }

    cout << sum << '\n';
  }

  return 0;
}
