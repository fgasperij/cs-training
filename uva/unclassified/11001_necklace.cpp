#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main() {
  int v, v0;
  cin >> v >> v0;
  while (v != 0 || v0 != 0) {
    double maxl = 0, l;
    int maxn = 0, n = 1;
    while (v > v0*n) {
      l = sqrt(((double)v)/n-v0);
      l = 0.3*l;
      l = n*l;
      if (maxl <= l) {
        if (fabs(l-maxl) < 1e-12) {
          maxl = 0;
          maxn = 0;
          break;
        }
        maxn = n;
        maxl = l;
      }
      ++n;
    }
    cout << maxn << '\n';

    cin >> v >> v0;
  }

  return 0;
}
