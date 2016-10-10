#include <iostream>

using namespace std;

int main() {
  long long p_left, k, h;
  cin >> p_left >> h >> k;

  long long  ch = 0, s = 0, next_p;
  cin >> next_p;
  ch = next_p;
  --p_left;
  if (p_left) cin >> next_p;
  while (ch || p_left) {
    while (p_left > 0 && next_p <= (h-ch)) {
      ch += next_p;
      --p_left;
      if (p_left) cin >> next_p;
    }

    if (ch >= k) {
      s += ch/k;
      ch = ch % k;
    } else {
      ++s;
      ch = 0;
    }
  }

  cout << s;

  return 0;
}
