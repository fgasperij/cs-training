#include <iostream>

using namespace std;

int main()
{
  int test_cases;
  cin >> test_cases;
  cin.ignore();

  for (int t = 0; t < test_cases; ++t) {
    /*
    if (t > 0) { 
      cout << endl;
    }
    */
    string tracks;
    getline(cin, tracks);
    int m = 0, f = 0;
    for (int i = 0; i < tracks.length(); ++i) {
      if (tracks[i] == 'M') {
        ++m;
      } else if (tracks[i] == 'F') {
        ++f;
      }
    }

    if (m == f && m > 1) {
      cout << "LOOP" << endl;
    } else {
      cout << "NO LOOP" << endl;
    }
  }

  return 0;
}
