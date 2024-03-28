// 46. Permutations

class Solution {
public:
    void generate(vector<int>& nums, int idx, vector<vector<int>>& result){
        int n = nums.size();
        if(idx == n-1){
            result.push_back(nums);
            return;
        }
        
        for(int i=idx;i<n; i++){
            swap(nums[idx], nums[i]);
            generate(nums, idx+1, result);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        generate(nums, 0, result);
        return result;
    }
};