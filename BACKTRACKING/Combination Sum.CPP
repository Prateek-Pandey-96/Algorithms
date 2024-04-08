// 39. Combination Sum

class Solution {
public:
    vector<vector<int>> result;
    void DFS(int idx, vector<int>& candidates, int target, vector<int>& temp){
        if(idx == candidates.size()){
            if(target == 0)
                result.push_back(temp);
            return;
        }
        DFS(idx+1, candidates, target, temp);
        
        if(target-candidates[idx]>=0)
        {
            temp.push_back(candidates[idx]);
            DFS(idx, candidates, target-candidates[idx], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> temp;
        DFS(0, candidates, target, temp);
        return result;
    }
};