// 1863. Sum of All Subset XOR Totals

class Solution {
public:
    void dfs(vector<int>& nums, int idx, int running_xor, int& total){
        if(idx==nums.size()){
            total += running_xor;
            return;
        }

        dfs(nums, idx+1, running_xor^nums[idx], total);
        dfs(nums, idx+1, running_xor, total);
    }
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        int running_xor = 0;
        dfs(nums, 0, running_xor, total);
        return total;
    }
};