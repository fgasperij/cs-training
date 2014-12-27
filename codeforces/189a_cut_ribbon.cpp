#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int ribbon[4001] = { };
  ribbon[0] = 1;

  for (int i = 1; i <= n; ++i) {
    int pieces_a = (a > i || ribbon[i-a] == 0) ? 0 : 1+ribbon[i-a];
    int pieces_b = (b > i || ribbon[i-b] == 0) ? 0 : 1+ribbon[i-b];
    int pieces_c = (c > i || ribbon[i-c] == 0) ? 0 : 1+ribbon[i-c];
    int max_pieces = max(pieces_a, pieces_b);
    ribbon[i] = max(max_pieces, pieces_c);
  }

  cout << ribbon[n]-1 << endl;

  return 0;
}
