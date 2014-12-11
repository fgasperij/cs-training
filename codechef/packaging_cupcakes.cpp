#include <iostream>

using namespace std;

int main()
{
  int test_cases;
  cin >> test_cases;

  int cupcakes;
  for (int i = 0; i < test_cases; ++i) {
    cin >> cupcakes;
    cout << (cupcakes/2)+1 << endl;
  }

  return 0;
    
}
