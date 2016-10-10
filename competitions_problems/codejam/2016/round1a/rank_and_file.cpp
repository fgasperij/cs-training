#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, casen = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int linesn = 2*n-1;
    vector<vector<int> > lines(linesn, vector<int> (n));
    for (int i = 0; i < linesn; ++i)
      for (int j = 0; j < n; ++j)
        cin >> lines[i][j];

    cout << "Case #" << casen++ << ": " << missing << '\n';
  }

  return 0;
}
