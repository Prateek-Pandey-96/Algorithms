// 684. Redundant Connection

class Solution {
public:
    int par[1005], rank[1005];
    int findParent(int a){
        while(par[a]!=a)
            a = par[a];
        return a;
    }
    void doUnion(int a, int b){
        int par_a = findParent(a);
        int par_b = findParent(b);
        if(par_a == par_b)
            return;
        if(rank[par_a]>=rank[par_b])
            par[par_b] = par_a;
        else
            par[par_a] = par_b;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0; i<1005; i++)
            par[i] = i, rank[i] = 0;
        for(vector<int> edge: edges){
            if(findParent(edge[0]) != findParent(edge[1]))
                doUnion(edge[0], edge[1]);
            else
                return edge;
        }
        return {};
    }
};