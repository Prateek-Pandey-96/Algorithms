// 90. Subsets II

class Solution {
public:
    void DFS(vector<int>& nums, int idx, vector<int> temp, vector<vector<int>>& result){
        if(idx == nums.size())
        {
            result.push_back(temp);
            return;
        }
        
        //include
        temp.push_back(nums[idx]);
        DFS(nums, idx+1, temp, result);
        temp.pop_back();

        // exclude
        int new_idx = idx+1;
        while(new_idx < nums.size() and nums[new_idx]==nums[idx])
            new_idx++;
        DFS(nums, new_idx, temp, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        DFS(nums, 0, temp, result);
        return result;
    }
};