// 1871. Jump Game VII

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length(), farthest = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front == n-1)
                return true;
            for(int i=max(front+minJump, farthest+1); i<= min(front+maxJump, n-1); i++){
                if(s[i]=='0')
                    q.push(i);
            }
            farthest = min(n-1, front+maxJump);
        }
        return false;
    }
};