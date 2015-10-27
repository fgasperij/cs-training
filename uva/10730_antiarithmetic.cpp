/*
 * started: 14:57
 * ac: 15:45
 * */

#include <iostream>
#include <vector>

using namespace std;

bool is_anti(vector<int> &w) {
  int n = w.size();
  int max_diff = (n+2)/3;
  for (int i = 1; i <= max_diff; ++i) {
    for (int j = 0; j+2*i < n; ++j) {
      if (w[j+i] > w[j] && w[j+2*i] > w[j+i]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int n;
  cin >> n;
  while (n) {
    cin.ignore(3, ':');
    vector<int> w(n);
    int temp;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      w[temp] = i;
    }

    cout << (is_anti(w) ? "yes" : "no") << '\n';

    cin >> n;
  }
  return 0;
}
