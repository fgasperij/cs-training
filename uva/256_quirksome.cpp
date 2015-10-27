#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
  int digits;
  cin >> digits;
  vector<vector<ll> > quirks(4, vector<ll>());
  while (!cin.eof()) {
    vector<ll> &c_quirks = quirks.at((digits-2)/2);
    if (c_quirks.empty()) {
      ll max = pow(10, digits/2);
      for (ll i = 0; i < max; ++i) {
        ll square = pow(i, 2);
        ll half_taker = pow(10, digits/2);
        ll left = square/half_taker;
        ll right = square % half_taker;
        if (left+right == i) {
          c_quirks.push_back(square);
        }
      }
    }

    for (int i = 0; i < c_quirks.size(); ++i) {
      cout << setw(digits) << setfill('0');
      cout << c_quirks[i] << '\n';
    }

    cin >> digits;
  }

  return 0;
}
