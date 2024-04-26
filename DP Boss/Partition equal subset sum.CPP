// 416. Partition Equal Subset Sum

class Solution {
public:
    bool RecursiveHelper(vector<int>& nums, int idx, int req_sum, int curr_sum, vector<vector<int>>& dp){
        if(idx == nums.size()){
            if(curr_sum == req_sum)
                return true;
            return false;
        }
        if(dp[idx][curr_sum]!=-1)
            return dp[idx][curr_sum];
        
        if(nums[idx] <= req_sum-curr_sum)
        {
            bool option1 = RecursiveHelper(nums, idx+1, req_sum, curr_sum, dp);
            bool option2 = RecursiveHelper(nums, idx+1, req_sum, curr_sum+nums[idx], dp);
            return dp[idx][curr_sum] = option1 || option2;
        }
        return dp[idx][curr_sum] = RecursiveHelper(nums, idx+1, req_sum, curr_sum, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;
        // odd sum can't be divided into two equal sum subsets
        if(sum%2)
            return false;
        int req_sum = sum/2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum/2 + 10, -1));
        return RecursiveHelper(nums, 0, req_sum, 0, dp);
    }
};