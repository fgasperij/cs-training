#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
     if (nums.empty()) return vector<int>();

     sort(nums.begin(), nums.end());

     int n = nums.size();
     vector<int> dp(n, 1);
     vector<int> next(n, -1);
     int max_length = 1, max_length_start = 0;
     for (int i = n-2; i >= 0; --i) {
         for (int j = i+1; j < n; ++j) {
             int new_length = dp[j] + 1;
             if (nums[j] % nums[i] == 0 && new_length > dp[i]) {
                 dp[i] = new_length;
                 next[i] = j;
                 if (max_length < new_length) {
                     max_length = new_length;
                     max_length_start = i;
                 }

             }
         }
     }

     vector<int> subset(max_length);
     int current = max_length_start, i = 0;
     while (current != -1) {
         subset[i++] = nums[current];
         current = next[current];
     }

     return subset;
}
