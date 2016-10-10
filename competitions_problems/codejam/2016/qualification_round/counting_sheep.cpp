#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  int casen = 1;
  while (t--) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << "Case #" << casen++ << ": INSOMNIA\n";
      continue;
    }

    vector<bool> seen(10, false);
    int left = 10, current = 0;
    while (left) {
      current += n;
      int pow = 1;
      while (current/pow > 0) {
        int digit = (current/pow) % 10;
        if (!seen[digit]) --left;
        seen[digit] = true;
        pow *= 10;
      }
    }

    cout << "Case #" << casen++ << ": " << current << '\n';
  }
}

