// 43. Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        string result(m+n, '0');
        // ensure num1 is always longer or equal to num2
        if(n>m)
            return multiply(num2, num1);
        int ctr = 1;
        for(int i=n-1; i>=0; i--){
            int idx = result.size()-ctr, carry = 0;
            ctr++;
            for(int j=m-1; j>=0; j--){
                int product = (num2[i]-'0') * (num1[j]-'0') + carry;
                int rem = (product + result[idx]-'0')%10;
                carry = (product + result[idx]-'0')/10;
                result[idx] = rem + '0';
                idx--;
            }
            if(carry)
                result[idx--] = carry + '0';
        }
        int i = 0;
        while(result[i]=='0')
            i++;
        if(i == result.size())
            return "0";
        return result.substr(i);
    }
};