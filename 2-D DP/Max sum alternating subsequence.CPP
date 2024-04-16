// 1911. Maximum Alternating Subsequence Sum

class Solution {
public:
    long long dfs(vector<int>& nums, int idx, int sign, vector<vector<long long>>& dp){
        if(idx >= nums.size())
            return 0;
        if(dp[idx][sign] != -1)
            return dp[idx][sign];
        int multiplier = sign == 1? 1: -1;
        int next_sign = sign==1? 0: 1;
        //select element
        long long p1 = (long long)nums[idx]*multiplier + dfs(nums, idx+1, next_sign, dp);
        //ignore element
        long long p2 = dfs(nums, idx+1, sign, dp);
        return dp[idx][sign]=max(p1, p2);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int i=0;
        int sign = 1; // positive; negative = sign = 0
        vector<vector<long long>> dp(nums.size()+1, vector<long long>(2, -1));
        return dfs(nums, i, sign, dp);
    }
};