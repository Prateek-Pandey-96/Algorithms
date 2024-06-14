// 945. Minimum Increment to Make Array Unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int moves = 0;

        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                continue;
            }else{
                moves += nums[i-1]+1 - nums[i];
                nums[i] = nums[i-1]+1;
            }
        }

        return moves;
    }
};