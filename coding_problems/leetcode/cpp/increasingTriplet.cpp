// Leetcode 334 . Increasing Triplet

    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        vector<int> maxAfter(n);
        maxAfter[n-2] = nums[n-1];
        for (int i = n-3; i >= 0; i--)
            maxAfter[i] = max(maxAfter[i+1], nums[i+1]);
        int minBefore = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (minBefore < nums[i] && nums[i] < maxAfter[i])
                return true;
            minBefore = min(minBefore, nums[i]);
        }
        return false;
    }