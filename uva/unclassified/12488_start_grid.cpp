/*
 * started: 16:39
 * ac: 17:08
 * */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (!cin.eof()) {
    vector<int> start(n);
    for (int i = 0; i < n; ++i) {
      cin >> start[i];
    }
    vector<int> end(n);
    for (int i = 0; i < n; ++i) {
      cin >> end[i];
    }
    vector<int> normalized(n);
    for (int i = 0; i < n; ++i) {
      bool found = false;
      for (int j = 0; j < n && !found; ++j) {
        if (end[j] == start[i]) {
          found = true;
          normalized[j] = i;
        }
      }
    }

    int takes = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (normalized[j] > normalized[i]) ++takes;
      }
    }

    cout << takes << '\n';

    cin >> n;
  }
  return 0;
}
