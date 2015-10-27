#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  cout << setprecision(30);
  float x = 10.0;
  cout << "FLOAT\n";
  for (int i = 0; i < 20; ++i) {
    x /= 10;
    cout << x << '\n';
  }
  double y = 10.0;
  cout << "DOUBLE\n";
  for (int i = 0; i < 20; ++i) {
    y /= 10;
    cout << y << '\n';
  }
  long double z = 10.0;
  cout << "LONG DOUBLE\n";
  for (int i = 0; i < 20; ++i) {
    z /= 10;
    cout << z << '\n';
  }
  
  return 0;
}
