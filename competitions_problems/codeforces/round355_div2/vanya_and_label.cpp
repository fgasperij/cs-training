#include <iostream>
#include <string>
#include <vector>

using namespace std;

const unsigned long long MOD = 1000000000 + 7;

int base64(char c) {
  if (c >= '0' && c <= '9') return c-'0';
  if (c >= 'A' && c <= 'Z') return (c-'A')+10;
  if (c >= 'a' && c <= 'z') return (c-'a')+36;
  if (c == '-') return 62;

  return 63;
}

int main() {
  vector<int> zeros(64, 0);
  for (int i = 0; i < 64; ++i) {
    int c = 0;
    for (int j = 0; j <= 5; ++j)
      if (((1 << j) & i) == 0) ++c;

    zeros[i] = c;
  }


  char c;
  int count = 0;
  cin >> c;
  while (!cin.eof()) {
    count += zeros[base64(c)];
    cin >> c;
  }

  unsigned long long r = 1;
  while (count--) {
    r *= 3;
    r %= MOD;
  }

  cout << r;

  return 0;
}
