#include <iostream>

using namespace std;

struct Test {
  int a;
  int b;

  Test(int aa, int bb) : a(aa), b(bb) {};
};

int main() {
  Test t(1, 2);
  cout << t.a << " " << t.b << '\n';

  return 0;
}
