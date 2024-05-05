// 682. Baseball Game

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> s;
        for(auto str:operations){
            if(str == "+"){
                int first = s.top(); s.pop();
                int second = s.top();
                s.push(first);
                s.push(first+second);
            }else if(str == "D"){
                int x = s.top();
                s.push(2*x);
            }else if(str == "C"){
                s.pop();
            }else{
                s.push(stoi(str));
            }
        }
        int ans = 0;
        while(!s.empty())
            ans += s.top(), s.pop();
        return ans;
    }
};