# Start reading: 10.32
# Finished reading 10.33
# Finished with questions: 10.35
# Finished coding: 10.40
# Finished testing: 10.42
# Passed: 10 45
# first submission failed
# second submission passed

# Questions

# - what are the lengths of the strings?
# - how are strings represented?
# - what are the possible characters? how can we do comparison?
# - how do you define unique? A == a? what about tildes?
# - can the string be empty?
# - can the string fit into memory?

# Tests

# - empty string
# - len 1 current = a, last_pos[a] = 0, max = 1
# - len 2 "aa", 

# last_pos (a, 0) (b, 2)
# left = 2
# right = 3
# max = 2

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_position = dict()
        left = 0
        right = 0
        max_length = 0
        while right < len(s):
            current = s[right]
            if current in last_position:
                left = max(left, last_position[current] + 1)

            last_position[current] = right
            max_length = max(max_length, right - left + 1)
    
            right = right + 1

        return max_length