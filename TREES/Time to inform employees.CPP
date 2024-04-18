// 1376. Time Needed to Inform All Employees

class Solution {
public:
    int dfs(int src, vector<int> tree[], vector<int>& informTime){
        int time = informTime[src];
        
        int additional_time = 0;
        for(auto dest: tree[src])
            additional_time = max(additional_time, dfs(dest, tree, informTime));
        
        return time+additional_time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> tree[n];
        for(int i=0; i<manager.size(); i++){
            if(manager[i]!=-1)
                tree[manager[i]].push_back(i);
        }
        return dfs(headID, tree, informTime);
    }
};