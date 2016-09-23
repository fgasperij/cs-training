#include <vector>
#include <iostream>
#include <limits>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
  if (nums.size() < 3) return false;

  int min = nums[0], min2 = numeric_limits<int>::max();
  for (auto e : nums) {
    if (e > min2) return true;
    if (e > min) {
      min2 = e;
    } else {
      min = e;
    }
  }

  return false;
}

int main() {
  vector<int> v = {1,2,-3,-9,4};
  cout << increasingTriplet(v) << endl;
  return 0;
}
