#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;


bool rep(long long n) {
  bool used[10] = {};
  while (n) {
    if (used[n%10]) return true;
    if (n%10 == 0) return true;
    used[n%10] = true;
    n /= 10;
  }

  return false;
}
bool is_runaround(long long run) {
  if (rep(run)) return false;
  char s[20];
  sprintf(s, "%lld", run);
  int sum = 0, curr = 0;
  bool used[10] = {};
  for (int j = 0; j < strlen(s); ++j) {
    curr = (curr + (s[curr]-'0')) % strlen(s);
    if (used[curr]) return false;
    used[curr] = true;
  }
  if (curr != 0) return false;

  return true;
}

int main() {
  int c = 1;
  long long max = 9876555;
  vector<long long> sols(max);
  for (long long i = sols.size()-2; i > 9; --i) {
    if (is_runaround(i)) {
      sols[i] = i;
    } else {
      sols[i] = sols[i+1];
    }
  }

  int run;
  cin >> run;
  while (run != 0) {
    cout << "Case " << c++ << ": " << sols[run] << '\n';
    cin >> run;
  }
}
