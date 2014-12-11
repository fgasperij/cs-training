#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;

  int result = a - b;
  int rest = result % 10;
  cout << result-rest+((rest+2) % 10) << endl;

  return 0;
}


