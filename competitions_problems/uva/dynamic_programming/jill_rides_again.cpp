// start: 19:27
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Test cases
// - istops = 2
// - max_nice > 0, == 0, < 0
// - part with max nice includes:
//  - first bus stop
//  - last bus stop
//  - just two bus stops
//  - 3 or more

int main() {
  int iroutes;
  cin >> iroutes;
  int i = 1;
  while (iroutes--) {
    int istops, stop;
    cin >> istops;
    long long max_nice = 0, max_l = -1, max_r = -1;
    long long curr_l = 1;
    long long sum = 0;
    for (int i = 1; i < istops; ++i) {
      cin >> stop;
      sum += stop;
      if (sum > max_nice || (sum == max_nice && i+1-curr_l > max_r-max_l)) {
        max_l = curr_l;
        max_r = i+1;
        max_nice = sum;
      }
      if (sum < 0) {
        sum = 0;
        curr_l = i+1;
      }
    }

    if (max_nice > 0) {
      cout << "The nicest part of route " << i++;
      cout << " is between stops " << max_l << " and " << max_r << '\n';
    } else {
      cout << "Route " << i++ << " has no nice parts\n";
    }
  }

  return 0;
}
