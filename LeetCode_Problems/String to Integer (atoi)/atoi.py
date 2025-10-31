# October 28, 2025
# 8. String to Integer (atoi) MEDIUM
# Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
# The algorithm for myAtoi(string s) is as follows:
# 1. Whitespace: Ignore any leading whitespace (" ").
# 2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
# 3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
# 4. Rounding: If the integer is out of the 32-bit signed integer range [-2**31, 2**31 - 1], then round the integer to remain in the range. Specifically, integers less than -2**31 should be rounded to -2**31, and integers greater than 2**31 - 1 should be rounded to 2**31 - 1.
# Return the integer as the final result.
class Solution:
    def myAtoi(self, s: str) -> int:
        
        INT_MAX = (2 ** 31) - 1
        INT_MIN = (-2 ** 31)
        
        i = 0
        n = len(s)

        result = 0
        isNegative = False

        while i < n and s[i] == " ":
            i += 1
        
        # Check for empty string(return 0)
        if i == n:
            return 0

        # Check for sign
        if s[i] == '-':
            isNegative = True
            i += 1
        elif s[i] == "+":
            i += 1
        
        while i < n and s[i].isdigit():
            digit = ord(s[i]) - ord('0') # ASCII conversion to actual int

            if result > (INT_MAX - digit) // 10:
                if isNegative:
                    return INT_MIN
                else:
                    return INT_MAX

            result = result * 10 + digit        
            
            i += 1

        if isNegative:
            return -1 * result
        else:
            return result

