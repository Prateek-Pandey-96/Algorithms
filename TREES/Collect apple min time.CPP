// 1443. Minimum Time to Collect All Apples in a Tree

class Solution {
public:
    // simple dfs on a tree
    int dfs(int src, int par, vector<int> tree[], vector<bool>& hasApple){
        int time = 0;
        for(auto dest: tree[src])
            if(dest != par)
                time += dfs(dest, src, tree, hasApple);
        
        if(src!=0)
            // if doesnt have apple but subtree had apples
            if(time != 0)
                time += 2;
            // if subtree doesnt have apples
            else
                time = hasApple[src]? 2: 0;
        cout<<src<<" "<<time<<endl;
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> tree[n];
        for(vector<int> edge: edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0, -1, tree, hasApple);
    }
};