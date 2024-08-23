# 592. Fraction Addition and Subtraction
from math import gcd
class Solution:
    def isNum(self, ch):
        if ch in ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']:
            return True
        return False
    
    def calculate(self, tup1, tup2):
        sign1, num1, den1 = tup1
        sign2, num2, den2 = tup2
        multiple1 = 1 if sign1 == '+' else -1
        multiple2 = 1 if sign2 == '+' else -1
        den_mul = int(den1) * int(den2)

        num_add = (int(den2)*int(num1)*multiple1) + (int(den1)*int(num2)*multiple2)
        gcd_num_den = gcd(den_mul, num_add)

        if num_add == 0:
            return ("#", '0', '0')
        if num_add < 0:
            return ('-', str(abs(num_add//gcd_num_den)), str(den_mul//gcd_num_den))
        return ('+', str(abs(num_add//gcd_num_den)), str(den_mul//gcd_num_den))

    def fractionAddition(self, expression: str) -> str:
        stack = []
        i, n = 0, len(expression)

        while i < n:
            sign, numerator, denominator = '', '', ''
            if expression[i] in ['-', '+']:
                sign = expression[i]
                i += 1
                num = []
                while i<n and expression[i]!='/':
                    num.append(expression[i])
                    i += 1
                i += 1
                den = []
                while i < n and self.isNum(expression[i]):
                    den.append(expression[i])
                    i += 1
                numerator = "".join(num)
                denominator = "".join(den)
                i -= 1
            else:
                sign = '+'
                num = []
                while i<n and expression[i]!='/':
                    num.append(expression[i])
                    i += 1
                i += 1
                den = []
                while i < n and self.isNum(expression[i]):
                    den.append(expression[i])
                    i += 1
                numerator = "".join(num)
                denominator = "".join(den)
                i -= 1
            tup = (sign, numerator, denominator)
            if len(stack)==0:
                stack.append(tup)
            else:
                res = self.calculate(stack[-1], tup)
                stack.pop()
                if res[0] != '#':
                    stack.append(res)
                
            i += 1
        if len(stack) == 0:
            return "0/1"
        sign, num, den = stack[-1]
        if sign == '+':
            return num + '/' + den
        return '-' + num + '/' + den