#include <iostream>
#include <unordered_map>

using namespace std;

// class Solution {
// public:

//Starting with any positive integer, replace the number by the sum of
//the squares of its digits, and repeat the process until the number equals 1
// (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy numbers.

  unordered_map<int, int> cache;
  #define inCache(e) (cache.find(e) != cache.end())

  int next(int n) {
    if (inCache(n))
      return cache[n];

    int res = 0, i = n;
    while (i) {
      res += (i % 10) * (i % 10);
      i /= 10;
    }
    return cache[n] = res;
  }

  bool isHappy(int n) {
    cache[1] = 1;
    cout << n << " ";
    while (!inCache(next(n))) {
      n = next(n);
      cout << " -> " << n << " ";
    }
    cout << " -> " << next(n) << endl;
    cout << endl;
    return next(n) == 1;
  }
// };

int main() {
  cout << isHappy(7) << endl;
  return 0;
}