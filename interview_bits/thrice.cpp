#include <vector>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main() {
  int dividend = -2147483648;
  int divisor = -10000000;

  if (divisor == 0) return numeric_limits<int>::max();
  long long n = dividend;
  long long d = divisor;
  int sign = 1;
  if ((n < 0 && d > 0) || (n > 0 && d < 0)) sign = -1;
  n = abs(n); d = abs(d);
  if (d == 1) return n*sign;
  long long tot = 0;
  while(d <= n) {
      long long t = d;
      long long c = 1;
      t <<= 1;
      while (t <= n) {
          c <<= 1;
          t <<= 1;
      }
      tot += c;
      t >>= 1;
      n -= t;
  }
  
  cout << tot*sign << '\n';

  return 0;
}
