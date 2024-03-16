// 53. Maximum Subarray - kadan's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we can keep an array that will store max_subarray till an idx
        int n = nums.size();
        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        int local_max = nums[0];
        int max_sum = nums[0];

        for(int i=1; i<n; i++){
            // dp[i] = max(nums[i], nums[i]+dp[i-1]);
            local_max = max(nums[i], nums[i]+local_max);
            max_sum = max(max_sum, local_max);
        }

        return max_sum;
    }
};