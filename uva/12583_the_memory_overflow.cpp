/*
 * started: 17:09
 * ac: 17:20
 * */

#include <iostream>
#include <string>

using namespace std;

int main() {
  int t, c = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int recognitions = 0;
    for (int i = 1; i < s.size(); ++i) {
      bool rec = false;
      for (int j = max(0, i-k); j < i && !rec; ++j) {
        if (s[j] == s[i]) {
          ++recognitions;
          rec = true;
        }
      }
    }

    cout << "Case " << c++ << ": " << recognitions << '\n';
  }

  return 0;
}
