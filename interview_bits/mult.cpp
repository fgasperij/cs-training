#include <iostream>
#include <string>

using namespace std;

int main() {
  string A; string B;
  cin >> A >> B;

  string res = "0";
  for (int i = A.size()-1; i >= 0; --i) {
      int a = A[i]-'0';
      string temp_mul;
      int c = 0;
      for (int j = B.size()-1; j >= 0; --j) {
          int b = B[j]-'0';
          int mult = a*b+c;
          c = mult/10;
          temp_mul += to_string(mult % 10);
      }
      if (c) {
          temp_mul += to_string(c);
      }
      
      c = 0;
      int it = A.size()-1-i;
      for (int k = 0; k < temp_mul.size(); ++k) {
          int t = temp_mul[k]-'0';
          int sum;
          if (it+k >= res.size()) {
              sum = t+c;
              res += (char)(sum%10+'0');
          } else {
              int r = res[it+k]-'0';
              sum = r+t+c;
              res[it+k] = (char)(sum%10+'0');
          }
          c = sum/10;
      }
      if (c) {
          res += to_string(c);
      }
      cout << res << " ";
  }

  int l = res.size()-1;
  while (l >= 0 && res[l] == '0') --l;
  res.resize(l+1);
  if (res.empty()) res = "0";

  reverse(res.begin(), res.end());

  cout << res << '\n';

  return 0;

}
