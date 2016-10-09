/*
  You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
  f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int find_max(const vector<int>& v) {
  if (v.empty()) throw "ArgumentError";

  int max_val = v[v.size()-1] + (v.size()-1);
  int min_val = v[v.size()-1] - (v.size()-1);
  int max_dist = 0;
  for (int i = v.size()-2; i >= 0; --i) {
    max_dist = max(max_dist, max(abs(v[i]-max_val),abs(v[i]-min_val))-i);
    max_val = max(max_val, v[i]+i);
    min_val = min(min_val, v[i]-i);
  }

  return max_dist;
}

int main() {
  vector<int> v1(1, 1);
  assert(0 == find_max(v1));

  vector<int> v2 = {1, 2, 3};
  assert(4 == find_max(v2));

  vector<int> v3 = {1, 10, 5, 6, 2};
  assert(11 == find_max(v3));

  vector<int> v4 = {1, 11, 5, 6, 7};
  assert(11 == find_max(v4));

  return 0;
}
