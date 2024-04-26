// 494. Target Sum

class Solution {
public:
    int dp[21][2002];
    int RecursiveHelper(vector<int>& nums, int& target, int curr_sum, int idx, int& sum){
        if(idx == nums.size()){
            if(curr_sum == target)
                return 1;
            return 0;
        }
        if(dp[idx][curr_sum + sum]!=-1)
            return dp[idx][curr_sum + sum];
        int take_positive = RecursiveHelper(nums, target, curr_sum + nums[idx], idx+1, sum);
        int take_negative = RecursiveHelper(nums, target, curr_sum - nums[idx], idx+1, sum);
        return dp[idx][curr_sum + sum] = take_positive + take_negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        int sum = 0;
        for(int element: nums)
            sum += element;
        return RecursiveHelper(nums, target, 0, 0, sum);
    }
};