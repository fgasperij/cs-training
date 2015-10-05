#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
  string s;
  cin>>s;

  map<char, bool> h;
  //map<char, bool>::iterator it;
  int odds = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (h.find(s[i]) == h.end() || h[s[i]] == false) {
      ++odds;
      h[s[i]] = true;
    } else {
      --odds;
      h[s[i]] = false;
    }
  }
   
  cout << (odds < 2 ? "YES" : "NO") << '\n';

  return 0;
}
