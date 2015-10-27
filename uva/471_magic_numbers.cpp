#include <iostream>

using namespace std;

bool rep(long long n) {
  bool use[10] = {};
  while (n) {
    if (use[n%10]) return true;
    use[n%10] = true;
    n /= 10;
  }

  return false;
}

int main() {
  long long max = 9876543210;
  int t;
  cin >> t;
  while (t--) {
    cin.ignore(10000, '\n');
    long long n;
    cin >> n;

    for (long long i = 1; i <= max; ++i) {
      long long num = n*i;
      if (num > max) break;
      if (!rep(num) && !rep(i)) {
        cout << num << " / " << i << " = " << n << '\n';
      }
    }

    if (t) cout << "\n";
  }

  return 0;
}
