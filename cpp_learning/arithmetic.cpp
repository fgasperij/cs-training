#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c;
  long aa, bb, cc;
  cout << "sizeof(int): " << sizeof(a) << '\n';
  long d;
  cout << "sizeof(long): " << sizeof(d) << '\n';
  cout << "sizeof(long long): " << sizeof(aa) << '\n';
  a = 1000000;
  b = 1000000;
  c = a*b;
  cout << "int=int*int " << c << '\n';
  aa = 1000000;
  bb = 1000000;
  cc = aa*bb;
  cout << "long=long*long " << cc << '\n';

  cout << "\nVECTOR\n";
  vector<int> v(10);
  v.push_back(5);
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';

  return 0;
}
