// 40. Combination Sum II

class Solution {
public:
vector<vector<int>> result;
    void DFS(int idx, vector<int>& candidates, int target, vector<int>& temp){
        if(idx == candidates.size()){
            if(target == 0)
                result.push_back(temp);
            return;
        }

        if(target-candidates[idx]>=0)
        {
            temp.push_back(candidates[idx]);
            DFS(idx+1, candidates, target-candidates[idx], temp);
            temp.pop_back();
        }

        int new_idx = idx+1;
        while(new_idx < candidates.size() and candidates[idx]==candidates[new_idx])
            new_idx++;

        DFS(new_idx, candidates, target, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        DFS(0, candidates, target, temp);
        return result;
    }
};