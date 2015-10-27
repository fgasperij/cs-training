#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

long long eval(vector<int>, long long);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int degree;
    cin >> degree;
    vector<int> v(degree+1);
    for (int i = 0; i < v.size(); ++i) {
      cin >> v[i];
    }

    int d, k;
    cin >> d >> k;

    long long n = 1;
    long long an = eval(v, n);
    int i = n*d;
    while (i < k) {
      ++n;
      an = eval(v, n);
      i += n*d;
    }

    cout << an << '\n';
  }

  return 0;
}

long long eval(vector<int> v, long long n) {
  long long an = 0;
  for (int i = 0; i < v.size(); ++i) {
    an += v[i]*pow(n, i);
  }

  return an;
}
