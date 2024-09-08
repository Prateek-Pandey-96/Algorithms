# 8. String to Integer (atoi)

class Solution:
    def myAtoi(self, s: str) -> int:
        is_negative = False
        num = []
        
        n, idx = len(s), 0
        while idx<n and s[idx]==' ':
            idx += 1
        if idx == n:
            return 0
        
        if s[idx]=='-':
            is_negative = True
            idx += 1
        elif s[idx]=='+':
            idx += 1

        for i in range(idx, n):
            ch = s[i]
            if ch.isdigit():
                num.append(ch)
            else:
                break
            
        res = ''.join(num)
        if res == '':
            res = '0'
        
        lower_limit = -pow(2, 31)
        upper_limit = pow(2, 31) - 1

        ans = int(res) * (-1 if is_negative else 1)
        if ans < lower_limit:
            ans = lower_limit
        elif ans > upper_limit:
            ans = upper_limit
        
        return ans