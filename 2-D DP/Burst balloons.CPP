// 312. Burst Balloons

class Solution {
public:
    int dp[504][504];
    int RecursiveHelper(vector<int>& nums, int low, int high){
        if(low>high)
            return 0;
        if(dp[low][high]!=-1)
            return dp[low][high];
        int score = INT_MIN;
        for(int i=low; i<=high; i++){
            score = max(score, RecursiveHelper(nums, low, i-1)+RecursiveHelper(nums, i+1, high)+nums[i]*nums[low-1]*nums[high+1]);
        }
        return dp[low][high]=score;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> padded_nums;
        padded_nums.push_back(1);
        for(int num: nums)
            padded_nums.push_back(num);
        padded_nums.push_back(1);
        memset(dp, -1, sizeof dp);
        return RecursiveHelper(padded_nums, 1, nums.size());
    }
};