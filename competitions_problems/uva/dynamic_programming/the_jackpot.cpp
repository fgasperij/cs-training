#include <iostream>
#include <algorithm>

using namespace std;

// Test cases
//
// - one positive
// - one negative
// - all negatives
// - all positives
// - last big positive
// - skipping negatives

int main() {
  int n;
  cin >> n;
  while (n != 0) {
    int max_streak = 0;
    int prev, tmp;
    cin >> prev;
    if (prev > max_streak) max_streak = prev;
    --n;
    while (n--) {
      cin >> tmp;
      prev = max(tmp, tmp+prev);
      max_streak = max(prev, max_streak);
    }

    if (max_streak > 0) {
      cout << "The maximum winning streak is " << max_streak << ".\n";
    } else {
      cout << "Losing streak.\n";
    }
    cin >> n;
  }
}
