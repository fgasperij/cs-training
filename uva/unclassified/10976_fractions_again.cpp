#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int k;
  cin >> k;
  while (!cin.eof()) {
    vector<pair<int,int> > v;
    for (int i = k+1; i <= k*2; ++i) {
      if ((k*i) % (i-k) == 0) {
        v.push_back(make_pair(i, (k*i)/(i-k)));
      }
    }

    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); ++i) {
      cout << "1/" << k << " = 1/" << v[i].second << " + 1/" << v[i].first << '\n'; 
    }

    cin >> k;
  }
}
