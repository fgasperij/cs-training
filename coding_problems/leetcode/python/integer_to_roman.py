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
    
class PowerOfTenToRoman:
    def __init__(self, power_of_ten: int, unit: str, fives: str, prev_unit: str):
        self.power_of_ten = power_of_ten
        self.unit = unit
        self.fives = fives
        self.prev_unit = prev_unit
    
    def can_convert(self, num: int) -> bool:
        return num >= self.power_of_ten and num <= self.power_of_ten * 10

    def convert(self, num: int) -> str:
        num = num // self.power_of_ten
        if num == 9:
            return self.unit + self.prev_unit
        if num >= 5:
            return self.fives + self.unit * (num - 5)
        if num == 4:
            return self.unit + self.fives
        
        return self.unit * num

class SolutionReadableAlternative:
    def intToRoman(self, num: int) -> str:
        result = []
        while num >= 1000:
            result.append("M")
            num = num - 1000

        powers_of_ten = [
            PowerOfTenToRoman(100, "C", "D", "M"),
            PowerOfTenToRoman(10, "X", "L", "C"),
            PowerOfTenToRoman(1, "I", "V", "X"),
        ]

        for power_to_roman in powers_of_ten:
            if power_to_roman.can_convert(num):
                result.append(power_to_roman.convert(num))
                num = num % power_to_roman.power_of_ten

        return "".join(result)