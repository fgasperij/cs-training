#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
  double d = 13.1;
  double d2 = 13.14;
  double d3 = 13.141;
  double d4 = 13.1415;

  cout << setprecision(2) << fixed;
  cout << "13.1: " << d << '\n';
  cout << "13.14: " << d2 << '\n';
  cout << "13.141: " << d3 << '\n';
  cout << "13.1415: " << d4 << '\n';

  return 0;
}
