#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  double pi = atan(1) * 4;

  for (int i = 0; i <= 15; ++i) {
    cout << setprecision(i) << pi << endl;
  }

  return 0;
}
