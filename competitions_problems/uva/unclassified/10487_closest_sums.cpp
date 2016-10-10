/*
 * started: 14:32
 * ac: 14:45
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int closest(int q, vector<int> &v) {
  int closest = numeric_limits<int>::max();
  for (int i = 0; i < v.size()-1; ++i) {
    for (int j = i+1; j < v.size(); ++j) {
      if (abs(closest-q) > abs(v[i]+v[j]-q)) {
        closest = v[i]+v[j];
      }
    }
  }

  return closest;
}

int main() {
  int n, c = 1;
  cin >> n;
  while (n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    int queries;
    cin >> queries;
    cout << "Case " << c++ << ":\n";
    for (int i = 0; i < queries; ++i) {
      int q;
      cin >> q;
      cout << "Closest sum to " << q << " is " << closest(q, v) << ".\n";
    }


    cin >> n;
  }
  return 0;
}
