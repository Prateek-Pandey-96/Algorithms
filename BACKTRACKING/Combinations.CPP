// 77. Combinations

class Solution {
public:
    void DFS(int curr_num, int& n, int& k, vector<int>& temp, vector<vector<int>>& result){
        if(curr_num > n){
            if(temp.size()==k)
                result.push_back(temp);
            return;
        }
        DFS(curr_num+1, n, k, temp, result);
        
        temp.push_back(curr_num);
        DFS(curr_num+1, n, k, temp, result);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        int curr_num = 1;
        vector<vector<int>> result;
        vector<int> temp;
        DFS(curr_num, n, k, temp, result);
        return result;
    }
};