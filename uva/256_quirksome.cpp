#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  int digits;
  cin >> digits;
  vector<vector<int> > quirks(4, vector<int>());
  while (!cin.eof()) {
    vector<int> &c_quirks = quirks.at((digits-2)/2);
    if (c_quirks.empty()) {
      int max = pow(10, digits/2);
      for (int i = 0; i < max; ++i) {
        int square = pow(i, 2);
        int half_taker = pow(10, digits/2);
        int left = square/half_taker;
        int right = square % half_taker;
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
