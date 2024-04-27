// 1584. Min Cost to Connect All Points

class Solution {
public:
    struct Edge{
        int to, from, weight;
        Edge(int to, int from, int weight){
            this->to = to;
            this->from = from;
            this->weight = weight;
        }
    };
    static bool compare(Edge a, Edge b){
        return a.weight < b.weight;
    }
    int par[1005], rank[1005];
    int findParent(int a){
        while(par[a]!=a)
            a = par[a];
        return a;
    }
    void doUnion(int a, int b){
        int pa = findParent(a);
        int pb = findParent(b);
        if(pa == pb)
            return;
        if(rank[pa]<rank[pb])
            par[pa] = pb;
        else if(rank[pb]<rank[pa])
            par[pb] = pa;
        else{
            par[pa] = pb;
            rank[pa]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i=0; i<1005; i++) 
            par[i]=i, rank[i]=0;
        
        int n = points.size();
        vector<Edge> edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                Edge edge = Edge(i, j, abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
                edges.push_back(edge);
            }
        }
        sort(edges.begin(), edges.end(), compare);

        long min_cost = 0;
        for(auto edge: edges){
            int to = edge.to;
            int from = edge.from;
            int weight = edge.weight;

            if(findParent(to)!=findParent(from)){
                doUnion(to, from);
                min_cost += weight;
            }
        }

        return min_cost;
    }
};