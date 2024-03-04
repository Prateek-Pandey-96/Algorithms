// 402. Remove K Digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (k>=n or num[0]=='0')
            return "0";
        
        string result;
        for(auto ch: num){
            while(result.size() and ch-'0' < result.back()-'0' and k){
                k--;
                result.pop_back();
            }
            result.push_back(ch);
        }
        while(k--)
            result.pop_back();
        
        int start_idx = -1;
        for(int i=0; i<result.length(); i++){
            if(result[i]!='0'){
                start_idx = i;
                break;
            }
        }
        if(start_idx == -1)
            return "0";
        return result.substr(start_idx);
    }
};