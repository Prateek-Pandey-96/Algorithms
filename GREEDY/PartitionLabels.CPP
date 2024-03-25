// 763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<int, pair<int,int>> pos;
        for(int i=0; i<n; i++){
            if(!pos.contains(s[i]))
                pos[s[i]-'a'] = {i, i};
            else
                pos[s[i]-'a'].second = i;
        }
        int start = 0;
        vector<int> result;

        while(start < n){
            int farthest = start;
            for(int i=start; i<=farthest and i<n; i++){
                farthest = max(farthest, pos[s[i]-'a'].second);
            }
            result.push_back(farthest-start+1);
            start=farthest+1;
        }
        
        return result;
    }
};