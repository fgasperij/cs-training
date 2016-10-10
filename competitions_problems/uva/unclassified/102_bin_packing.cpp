#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
  map<char, int> colors;
  colors['B'] = 0;
  colors['C'] = 2;
  colors['G'] = 1;

  vector<vector<int> > bins(3, vector<int>(3));
  cin >> bins[0][0];
  while (!cin.eof()) {
    cin >> bins[0][1];
    cin >> bins[0][2];
    for (int i = 1; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> bins[i][j];
      }
    }

    int min_moves = numeric_limits<int>::max();
    string min_config;
    string perms("BCG");
    int moves;
    for (int i = 0; i < 6; ++i) {
      moves = 0;
      moves += bins[1][colors[perms[0]]] + bins[2][colors[perms[0]]];
      moves += bins[0][colors[perms[1]]] + bins[2][colors[perms[1]]];
      moves += bins[0][colors[perms[2]]] + bins[1][colors[perms[2]]];
      if (moves < min_moves) {
        min_moves = moves;
        min_config = perms;
      }
      next_permutation(perms.begin(), perms.end());
    }

    cout << min_config << " " << min_moves << '\n';

    cin >> bins[0][0];
  }

  return 0;
}
