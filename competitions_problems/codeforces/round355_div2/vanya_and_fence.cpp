#include <iostream>

using namespace std;

int main() {
  int n, h;
  cin >> n >> h;

  int hi, w = 0;
  while (n--) {
    cin >> hi;
    w += hi > h ? 2 : 1;
  }
    
  cout << w;

  return 0;
}
