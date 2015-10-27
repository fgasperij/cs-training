#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Range {
  int lower;
  int higher;
  string brand;
  Range(int l, int h, string b) : lower(l), higher(h), brand(b) {};
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d; cin >> d;
    vector<Range> ranges;
    int l, h; string b;
    for (int i = 0; i < d; ++i) {
      cin >> b >> l >> h;
      Range r(l, h, b);
      ranges.push_back(r);
    }

    int q; cin >> q;
    int p;
    for (int i = 0; i < q; ++i) {
      cin >> p; bool found = false, undet = false;
      string maker;
      for (int j = 0; j < d; ++j) {
        if (p >= ranges[j].lower && p <= ranges[j].higher) {
          if (found) {
            undet = true;
            break;
          }
          found = true;
          maker = ranges[j].brand;
        }
      }
      if (found && !undet) {
        cout << maker << '\n';
      } else {
        cout << "UNDETERMINED\n";
      }
    }
    if (t > 0) cout << '\n';
  }

  return 0;
}
