#include <string>
#include <iostream>

using namespace std;

int consume(char c, string& tower, int i) {
  while (i < tower.size() && tower[i] == c) ++i;
  return i;
}

int main() {
  int t, casen = 1;
  cin >> t;
  while (t--) {
    string tower;
    cin >> tower;
    int i = 0, moves = 0;
    if (tower[0] == '-') {
      ++moves;
      i = consume('-', tower, i);
    }
    while (i < tower.size()) {
      i = consume('+', tower, i);
      if (i == tower.size()) continue;
      i = consume('-', tower, i);
      moves += 2;
    }

    cout << "Case #" << casen++ << ": " << moves << '\n';
  }

  return 0;
}
