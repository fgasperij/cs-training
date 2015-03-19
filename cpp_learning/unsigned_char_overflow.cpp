#include <iostream>

using namespace std;

int main()
{
  char c = 200;
  cout << "c: " << (int)c << endl;
  c += 50;
  cout << "c: " << (int)c << endl;
  c += 5;
  cout << "c: " << (int)c << endl;
  c += 1;
  cout << "c: " << (int)c << endl;
  c += 50;
  cout << "c: " << (int)c << endl;

  return 0;
}
