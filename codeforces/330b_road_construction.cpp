// to ac: 8:11
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	int n, m, j, k;
	int is_restricted[1001];

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
	  cin >> k >> j;	
    is_restricted[k] = true;
    is_restricted[j] = true;
	}

  cout << n-1 << endl;
  int x = 1;
  while (is_restricted[x]) { x++; }
  for (int i = 1; i <= n ; i++) {
    if (i != x) {
      cout << x << ' ' << i << endl;
    }
  }

	return 0;
}
