#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum(int psums[], int l, int r, int size) {
  if (l < 0) {
    l = 0;
  }
  if (r >= size) {
    r = size-1;
  }
  if (l == 0) {
    return psums[r];
  }

  return (psums[r] - psums[l-1]);
}

int main() {
  const int MOD = int(1e9) + 7;
  const int n = 314159;
  const int MAX_SIZE = int(1e5) * 5;
  const int MAX_LENGTH = int(1e5);
  int a[MAX_SIZE], b[MAX_SIZE];
  fill(a, a+MAX_SIZE, 0);
  fill(b, b+MAX_SIZE, 0);

  string sa, sb;
  cin >> sa >> sb;

  for (int i = 0; i < sa.length(); ++i) 
    a[i] = sa[i] - '0';
  for (int i = 0; i < sb.length(); ++i) 
    b[i] = sb[i] - '0';

  // psums of ones
  int psums[MAX_LENGTH];
  psums[0] = b[0];
  for (int i = 1; i < sb.length(); ++i) {
    psums[i] = psums[i-1] + b[i];
  }

  int MAX_INDEX = (sb.length()-1) + n;
  int curr_pow = 1;
  int ans = 0;
  for (int i = 0; i <= MAX_INDEX; ++i) {
    int ones = sum(psums, i-n, i, sb.length());
    if (a[i] == 1) {
      ans = (ans + ((n+1)-ones) * 1LL * curr_pow) % MOD;
    } else {
      ans = (ans + ones * 1LL * curr_pow) % MOD;            
    }
    curr_pow = (curr_pow*2) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
