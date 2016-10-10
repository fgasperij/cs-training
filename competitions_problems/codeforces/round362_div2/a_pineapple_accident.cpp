#include <iostream>

using namespace std;

int main () {
  long long x, t, s;
  cin >> t >> s >> x;

  if (x == t || (x > t && (x-t) % s == 0)
      || (x > (t+1) && ( x-(t+1) ) % s == 0))
    cout << "YES";
  else
    cout << "NO";

  cout << endl;

  return 0;


}
