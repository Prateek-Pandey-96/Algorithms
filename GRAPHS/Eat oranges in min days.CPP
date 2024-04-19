// 1553. Minimum Number of Days to Eat N Oranges
class SolutionA {
public:
    int minDays(int n) {
        queue<int> q;
        q.push(n);
        int level = 0;
        unordered_set<int> visited;
        visited.insert(n);
        while(!q.empty()){
            int size = q.size();
            level += 1;
            while(size--){
                int front = q.front();
                q.pop();
                if(front==0)
                    return level-1;
                int to_push = -1;
                if(front%2 == 0){
                    to_push = front - front/2;
                    if(!visited.contains(to_push))
                        q.push(to_push), visited.insert(to_push);
                }
                if(front%3 == 0){
                    to_push = front - 2*(front/3);
                    if(!visited.contains(to_push))
                        q.push(to_push), visited.insert(to_push);
                }
                if(!visited.contains(front-1))
                    q.push(front-1);
            }
        }
        return -1;
    }
};


// 1553. Minimum Number of Days to Eat N Oranges better solution

class SolutionB {
public:
    unordered_map<int, int> dp;
    int dfs(int n){
        if(n==0 || n==1)
            return n;
        if(dp.contains(n))
            return dp[n];
        int days = n;
        return dp[n] = min(days, 1 + min(n%2 + dfs(n/2), n%3 + dfs(n/3)));
    }
    int minDays(int n) {
        dp.clear();
        return dfs(n);
    }
};