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
    
class SolutionWithPerfOptimization:
    def intToRoman(self, num: int) -> str:
        result = []

        while num >= 1000:
            result.append("M")
            num = num - 1000

        if num >= 900:
            result.append("CM")
            num = num - 900
        
        if num >= 500:
            result.append("D")
            num = num - 500
        
        if num >= 400:
            result.append("CD")
            num = num - 400

        while num >= 100:
            result.append("C")
            num = num - 100

        if num >= 90:
            result.append("XC")
            num = num - 90
        
        if num >= 50:
            result.append("L")
            num = num - 50
        
        if num >= 40:
            result.append("XL")
            num = num - 40

        while num >= 10:
            result.append("X")
            num = num - 10

        if num == 9:
            result.append("IX")
            return "".join(result)
        
        if num >= 5:
            result.append("V")
            num = num - 5

        if num == 4:
            result.append("IV")
            return "".join(result)
        
        while num >= 1:
            result.append("I")
            num = num - 1

        return "".join(result)