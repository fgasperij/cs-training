#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D;
int DELTA = 250;
int DP[30010][500];
int was[30010][500];
int cnt[30010];
int MX = int(3e4);
int dp(int loc, int delta)
{
  if (loc > MX) return 0;
  if (delta + D <= 0) return 0;
  // so -250 <= delta < 250 = DELTA
  int& x = DP[loc][delta+DELTA];
  if (was[loc][delta+DELTA]) return x;
  was[loc][delta+DELTA]=1;
  x = 0;
  x = max(x, dp(loc+D+delta+1,delta+1) );
  x = max(x, dp(loc+D+delta,delta) );
  x = max(x, dp(loc+D+delta-1,delta-1) );
  x += cnt[loc];
  return x;
}
int main()
{
  ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0);
  cin >> N >> D;
  for (int i = 1; i <= N; ++i) {
    int p;
    cin >> p;
    ++cnt[p];
  }
  cout << dp(D,0) << endl;
}
