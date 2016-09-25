/*
  Find out the maximum sub-array of non negative numbers from an array.
  The sub-array should be continuous. That is, a sub-array created by choosing the
  second and fourth element and skipping the third element is invalid.
  Maximum sub-array is defined in terms of the sum of the elements in the sub-array.
  Sub-array A is greater than sub-array B if sum(A) > sum(B).

  Questions

  - what must the function return? It could return the subarray, a couple of indices, the sum.
  return the subarray
  - what happens in the case of a tie of the value of the sum?
  return the longer one
  - what happens in the case of a tie of lengths?
  return the one with the minimum starting index
  - if there are no non-negative numbers, it's okay to return an empty vector?
  yes, return an empty array
  - do the values fall in any range? do we have any upper bound for the number of elements?
  no --> watch out for overflow
  s

*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> maxSet(const vector<int>& v) {
  int best_l = -1, best_r = -1, l = -1;
  long long best_sum = -1, curr_sum = -1;
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] < 0) {
      l = -1;
      continue;
    }

    if (l == -1) {
      l = i;
      curr_sum = v[i];
    } else {
      curr_sum += v[i];
    }

    if (curr_sum > best_sum || (curr_sum == best_sum && best_r-best_l < (int)i+1-l)) {
      best_l = l;
      best_r = i+1;
      best_sum = curr_sum;
    }
  }

  if (best_sum == -1) return vector<int>();

  return vector<int>(v.begin()+best_l, v.begin()+best_r);
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<int> max_sub = maxSet(v);

  for (auto e : max_sub) cout << e << " ";
  cout << endl;
}
