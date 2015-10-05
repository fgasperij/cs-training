#include <iostream>
#include <limits>

using namespace std;

int main() {
  int na, nb, ka, kb;
  cin >> na >> nb >> ka >> kb;

  int i = ka, ca;
  while (i--) {
    cin >> ca;
  }
  if (na-ka > 0) {
    cin.ignore(numeric_limits<int>::max(), '\n');
  }
  int cb;
  i = nb-kb+1;
  while (i--) {
    cin >> cb;
  }
  if (nb-kb > 0) {
    cin.ignore(numeric_limits<int>::max(), '\n');
  }

  cout << (ca<cb ? "YES" : "NO") << '\n';

  return 0; 
}
