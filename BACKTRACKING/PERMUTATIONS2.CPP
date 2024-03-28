// 47. Permutations II

class Solution {
public:
    void generate(vector<int>& nums, int idx, set<vector<int>>& result){
        int n = nums.size();
        if(idx == n-1){
            result.insert(nums);
            return;
        }
        
        for(int i=idx;i<n; i++){
            swap(nums[idx], nums[i]);
            generate(nums, idx+1, result);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> result;
        generate(nums, 0, result);
        vector<vector<int>> res(result.begin(), result.end());
        return res;
    }
};