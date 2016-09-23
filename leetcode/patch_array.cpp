/*
 * 330. Patching array
 * Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that 
 * any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the 
 * minimum number of patches required.
 **/

#include <vector>
#include <cmath>

using namespace std;

int minPatches(vector<int>& nums, int n) {
  if (nums.empty() || nums[0] > n) return floor(log2(n)+1);

  int added = ceil(log2(nums[0]));
  long long sums = (1 << added) - 1;
  int i = 0;
  while (i < nums.size() && nums[i] <= n && sums < n) {
    while (sums < nums[i]-1) {
      ++added;
      sums += sums + 1;
    }
    sums += nums[i++];
  }

  while (sums < n) {
    ++added;
    sums += sums + 1;
  }

  return added;
}
