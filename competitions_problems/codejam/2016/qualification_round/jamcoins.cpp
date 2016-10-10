#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n, j;
  cin >> n >> n >> j;
  vi coins(j, 0);
  vvi divs(j, vi (9, 0));




  cout << "Case #1:\n";
  for (int i = 0; i < j; ++i) {
    cout << coins[i] << " ";
    for (int k = 0; k < 9; ++k) {
      cout << divs[j][k];
      if (k != 8) cout << " ";
    }
    cout << '\n';
  }

  return 0;
}
