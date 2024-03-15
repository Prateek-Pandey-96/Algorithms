// 377. Combination Sum IV

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> ways(target+1, 0);
        ways[0] = 1;

        for(int i=1; i<=target; i++){
            for(int idx=0; idx<n; idx++){
                if(nums[idx]<=i)
                    ways[i] += ways[i-nums[idx]];
            }
        }

        return ways[target];
    }
};