// 91. Decode Ways

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;  // base case
        dp[1] = 1;  // ways to decode string of length 1 is 1 provided string is not '0'

        for(int len=2; len<=n; len++){
            int idx = len-1;
            if(s[idx]!='0')
            {
                dp[len] = dp[len] + dp[len-1];
                if(s[idx-1]=='1' and s[idx]>='1' and s[idx]<='9')
                    dp[len] = dp[len] + dp[len-2];
                else if(s[idx-1]=='2' and s[idx]>='1' and s[idx]<='6')
                    dp[len] = dp[len] + dp[len-2];
            }else{
                if(s[idx-1]=='1' or s[idx-1] == '2')
                    dp[len] = dp[len] + dp[len-2];
            }
        }

        return dp[n];
    }
};