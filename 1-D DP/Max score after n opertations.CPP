// 1799. Maximize Score After N Operations
class Solution {
public:
    int dp[(1<<15)];
    int RecursiveHelper(vector<int>& nums, int& mask, int turn){
        if(turn > nums.size()/2)
            return 0;
        if(dp[mask]!=-1)
            return dp[mask];
        int max_score = 0;
        for(int i=0; i<nums.size(); i++){
            if((mask & (1<<i)))
                continue;
            mask = mask | (1<<i);
            for(int j=i+1; j<nums.size(); j++){
                if((mask & (1<<j)))
                    continue;
                mask = mask | (1<<j);
                int score = turn * __gcd(nums[i], nums[j]) + RecursiveHelper(nums, mask, turn+1);
                max_score = max(max_score, score);
                mask = mask ^ (1<<j);
            }
            mask = mask ^ (1<<i);
        }
        return dp[mask]=max_score;
    }
    int maxScore(vector<int>& nums) {
        // try all possibilties
        int len = nums.size();
        int mask = 1<<len;
        memset(dp, -1, sizeof dp);
        return RecursiveHelper(nums, mask, 1);
    }
};