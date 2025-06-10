# Start to read: 12.10
# Questions: 12.15
# Think approach: 12.17
# Finished coding: 12.28

# - arbitrary large numbers? max 3999
# - how would you do the max? MMMCMXCIX
# - what about negative numbers? 0?

# Approach

# go from biggest to smallest and use them all you can

class Solution:
    def intToRoman(self, num: int) -> str:
        result = []
        numerals = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I")
        ]

        for val, roman in numerals:
            while num >= val:
                result.append(roman)
                num = num - val

        return "".join(result)