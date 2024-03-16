// 55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int start = 0 , end = nums[0];

        for(int i = start; i<= end; i++){
            end = max(end, i+nums[i]);
            if(end >= n-1)
                return true;
        }

        return false;
    }
};