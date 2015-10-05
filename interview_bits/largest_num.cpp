#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool comp(int i,int j) { 
  string si = to_string(i);
  string sj = to_string(j);
  string tempi = si + sj, tempj = sj + si;
  return atoi(tempi.c_str()) > atoi(tempj.c_str());
}

string largestNumber(const vector<int> &A) {
  vector<int> B = A;
  sort(B.begin(), B.end(), comp);

  string result;
  for (int i = 0; i < B.size(); ++i) {
    result.append(to_string(B[i]));
  }

  return result;
}

int main() {
  vector<int> v;
  v.push_back(3);
  v.push_back(30);
  v.push_back(9);
  v.push_back(98);

  string res = largestNumber(v);
  cout << res << '\n';

  return 0;
}
