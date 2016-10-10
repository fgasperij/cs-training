/*
  PROBLEM STATEMENT
  You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN.
  In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the
  characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
  Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you
  don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements
  denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int val(const char c) {return c == '0' ? 1 : -1;}

vector<int> flip(string A) {
  if (A.empty()) return vector<int>();

  int best_l = 0, best_r = 0, curr_l = 0;
  int prev = val(A[0]);
  int best_sum = prev;
  for (size_t i = 1; i < A.size(); ++i) {
    int curr_val = val(A[i]);
    if (prev < 0) {
      curr_l = i;
      prev = curr_val;
    } else {
      prev += curr_val;
    }
    if (prev > best_sum) {
      best_l = curr_l;
      best_r = i;
      best_sum = prev;
    }
  }

  if (best_sum <= 0) return vector<int>();

  vector<int> res(2, 0);
  res[0] = best_l;
  res[1] = best_r;

  return res;
}

int main() {
  string A;
  cin >> A;

  vector<int> interval = flip(A);

  if (interval.empty()) {
    cout << "Don't flip a thing man, there are only ones!";
  } else {
    cout << "l = " << interval[0] << " r = " << interval[1];
  }

  cout << endl;

  return 0;
}
