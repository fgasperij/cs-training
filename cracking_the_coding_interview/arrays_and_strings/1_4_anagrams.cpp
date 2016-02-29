#include <iostream>
#include <string>

using namespace std;

bool check_anagrams(string s1, string s2) {
  if (s1.length() != s2.length()) return false;

  int n = s1.length();
  if (n == 0) return true;

  int counts[256];
  for (int i = 0; i < 256; ++i) counts[i] = 0;

  for (int i = 0; i < n; ++i) ++counts[s1[i]];
  for (int i = 0; i < n; ++i) {
    --counts[s2[i]];
    if (counts[s2[i]] < 0) return false;
  }

  return true;
}

int main() {
  char s[] = "zxcvbnmasfjfjr";
  sort(s, s+14);
  cout << s << '\n';
  int ar[] = {10, 24832,23,234,11,998};
  sort(ar, ar+6);
  for (int i = 0; i < 6; ++i) {
    cout << ar[i] << " ";
  }
  cout << '\n';

  return 0;
}
