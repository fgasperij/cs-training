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
    int mins = v[n-1];
    int maxd = v[n-2]-mins;
    for (int i = n-3; i >= 0; --i) {
      mins = min(mins, v[i+1]);
      maxd = max(maxd, v[i]-mins);
    }
    cout << maxd << '\n';
  }

  return 0;
}
