// 78. Subsets

class Solution {
public:
    void DFS(vector<int>& nums, int idx, vector<int> temp, vector<vector<int>>& result){
        if(idx == nums.size())
        {
            result.push_back(temp);
            return;
        }
        
        // exclude
        DFS(nums, idx+1, temp, result);
        //include
        temp.push_back(nums[idx]);
        DFS(nums, idx+1, temp, result);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        DFS(nums, 0, temp, result);
        return result;
    }
};