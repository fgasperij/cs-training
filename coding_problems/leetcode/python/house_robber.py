# start: 9.16
# finished questions 9.18
# finished approach 09.22
# finished coding 9.25
# accepted first time

# summary

# - can't rob two adjacent houses
# - max amount of money without alerting the police

# questions

# - what if there are no houses?
# - is the amount of money integers? floats?
# - could there be a negative amount of money?
# - adjacent means they are +1 or -1?
# - first and last house only have one adjacent?

# approaches

# - brute force: generate all subsets of houses, filter out the ones
# that would alert the police, sum the rest and pick the max
# O(n * 2 ^ n)

# - calculate the max amount of money you can make by picking
# house i as your last house
# f(i) = money[i] + max(f(i-2), f(i-3))
# then take max(f(n-1), f(n-2))
# time: O(n) space: O(n) assuming you can't reuse the input array

# tests

# - no houses
# - one house
# - two houses
# - make sure it picks the biggest
# [1, 32, 4, 1000, 0]
# max_money
# [1, 32, 5, 1032, 32]
# - make sure it ignores small one next to big

from typing import List


class Solution:
    def robWithoutModifyingTheInput(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])

        max_money = nums.copy()
        max_money[2] = max_money[2] + nums[0]
        for i in range(3, len(nums)):
            max_money[i] = nums[i] + max(max_money[i-2], max_money[i-3])

        return max(max_money[-1], max_money[-2]) 

    def robModifyingTheInput(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])

        nums[2] = nums[2] + nums[0]
        for i in range(3, len(nums)):
            nums[i] = nums[i] + max(nums[i-2], nums[i-3])

        return max(nums[-1], nums[-2]) 