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

class SolutionWithPerfOptimization:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_position = dict()
        left = 0
        right = 0
        max_length = 0
        for right in range(0, len(s)):
            if s[right] in last_position and left < last_position[s[right]] + 1:
                left = last_position[s[right]] + 1

            last_position[s[right]] = right
            max_length = max_length if max_length > right - left + 1 else right - left + 1

        return max_length
    
class SolutionClear:

    def __init__(self):
        self.rightmost_position_for = dict()
        self.sliding_window_left = 0

    def rightmost_position_for_char_yet(self, current_char: str) -> int:
        if current_char in self.last_position:
            return self.rightmost_position_for[current_char]
        
        return -1
    
    def is_char_in_sliding_window(self, current_char: str) -> bool:
        seen_current_char = current_char in self.rightmost_position_for
        
        return seen_current_char and self.rightmost_position_for[current_char] >= self.sliding_window_left
    
    def update_sliding_window_left_to_only_include_current_char_once(self, current_char: str):
        rightmost_position = self.rightmost_position_for_char_yet(current_char)
        if rightmost_position >= self.sliding_window_left:
            self.sliding_window_left = rightmost_position + 1

    def update_rightmost_position_for(self, current_char: str, sliding_window_right: int):
        self.rightmost_position_for[current_char] = sliding_window_right

    def lengthOfLongestSubstring(self, s: str) -> int:
        self.rightmost_position_for = dict()
        
        self.sliding_window_left = 0
        max_length_substring_without_repeating = 0
        
        for sliding_window_right in range(0, len(s)):
            current_char = s[sliding_window_right]
            if self.is_char_in_sliding_window(current_char):
                self.update_sliding_window_left_to_only_include_current_char_once(current_char)

            self.update_rightmost_position_for(current_char, sliding_window_right)
            
            max_length = max(max_length, sliding_window_right - self.sliding_window_left + 1)

        return max_length
    
class SlidingWindow:
    def __init__(self, s: str):
        self.s = s
        self.left = 0
        self.right = 0

    def has_next(self):
        return self.right < len(self.s)

    def slide_right(self):
        self.right += 1

    def slide_left_to(self, to: int):
        self.left = to

    def length(self):
        return self.right - self.left + 1

class Solution:

    def is_char_in_sliding_window(self, current_char: str) -> bool:
        if current_char in self.rightmost_position_for:
            return self.rightmost_position_for[current_char] >= self.sliding_window.left
        
        return False

    def lengthOfLongestSubstring(self, s: str) -> int:
        sliding_window = SlidingWindow(s)
        self.rightmost_position_for = dict()
        max_length_substring_without_repeating = 0

        while sliding_window.has_next():
            current_char = s[sliding_window.right]
            if self.is_current_char_in_sliding_window(current_char):
                new_left = self.rightmost_position_for[current_char] + 1
                sliding_window.slide_left_to(new_left)
            
            self.rightmost_position_for[current_char] = sliding_window.right
            
            max_length_substring_without_repeating = max(max_length_substring_without_repeating, sliding_window.length())
    
            sliding_window.move_right()

        return max_length_substring_without_repeating