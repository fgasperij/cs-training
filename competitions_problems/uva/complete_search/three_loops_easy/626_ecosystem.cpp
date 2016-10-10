#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  while (!cin.eof()) {
    if (count != 0) {
      cout << '\n';
    } else {
      ++count;
    }
    vector<vector<bool> > eat_relation (n, vector<bool> (n, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char t;
        cin >> t;
        eat_relation[i][j] = t == '1';
      }
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || !eat_relation[i][j]) continue;
        for (int k = 0; k < n; ++k) {
          if (k == j || k == i || 
              !eat_relation[j][k] || !eat_relation[k][i] ||
              (!(i < j && j < k) && !(i > j && j > k))) continue;
          cout << i+1 << " " << j+1 << " " << k+1 << '\n';
          ++total;
        }
      }
    }

    cout << "total:" << total << '\n';
    cin >> n;
  }
  cout << '\n';

  return 0;
}
