#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  while (n--) {
    cin >> v[n];
  }

  sort(v.begin(), v.end());
 // for (int i = 0; i < v.size(); ++i) {
 //   cout << v[i] << " ";
 // }
 // cout << '\n';

  int min_diff = abs(v[0] - v[v.size()-1]);
  vector<pair<int, int> > pairs;
  for (int i = 0; i < v.size()-1; ++i) {
    int current = abs(v[i]-v[i+1]);
    if (current == min_diff) {
      pairs.push_back(make_pair(v[i], v[i+1]));
    } else if (current < min_diff) {
      min_diff = current;
      pairs.erase(pairs.begin(), pairs.end());
      pairs.push_back(make_pair(v[i], v[i+1]));
    }
  }

  for (int i = 0; i < pairs.size(); ++i) {
    cout << pairs[i].first << " " << pairs[i].second;
    if (i < pairs.size()-1) cout << " ";
  }
  cout << '\n';

  return 0;
}
