#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Plusonegame {

  public:

    string getorder(string s) {
      int n = s.size();
      sort(s.begin(), s.end());
      int d = 0;
      while (d < n && s[d] == '+') ++d;

      if (d == n || d == 0) return s;

      int count = 0, i = 0;
      while (i < d && d < n) {
        while (i < d && count < (s[d]-'0')) {
          ++count; ++i;
        }
        while (i < d && d < n && (s[d]-'0') == count) swap(s[i++], s[d++]);
      }
      
      return s;
    }

};
