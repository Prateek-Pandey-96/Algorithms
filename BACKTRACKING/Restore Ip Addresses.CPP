//93. Restore IP Addresses

class Solution {
public:
    void DFS(string s, int idx, int integer_cnt, string temp, vector<string>& result){
        if(idx >= s.length()){
            if(integer_cnt == 4)
            {
                temp.pop_back();
                result.push_back(temp);
            }
            return;
        }

        string prev1 = s.substr(idx, 1);
        DFS(s, idx+1, integer_cnt+1, temp + prev1 + '.', result);

        if(s.length()-idx >= 2)
        {
            string prev2 = s.substr(idx, 2);
            if(stoi(prev2)>=10 and stoi(prev2)<=99)
            {
                DFS(s, idx+2, integer_cnt+1, temp + prev2 + '.', result);
            }
        }   
            
        if(s.length()-idx >= 3)
        {
            string prev3 = s.substr(idx, 3);
            if(stoi(prev3)>=100 and stoi(prev3)<=255)
            {
                DFS(s, idx+3, integer_cnt+1, temp + prev3 + '.', result);
            }
        }   
    }

    vector<string> restoreIpAddresses(string s) {
        string temp;
        vector<string> result;
        int integer_cnt = 0;
        DFS(s, 0, integer_cnt, temp, result);
        return result;
    }
};