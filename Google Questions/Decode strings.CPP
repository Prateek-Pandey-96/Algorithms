// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        string result;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]!=']')
                result.push_back(s[i]);
            else{
                string str;
                while(result.size() and result.back() != '['){
                    str.push_back(result.back());
                    result.pop_back();
                }
                result.pop_back();
                reverse(str.begin(), str.end());
                string num;
                while(result.size() and result.back() >= '0' and result.back() <= '9'){
                    num.push_back(result.back());
                    result.pop_back();
                }
                reverse(num.begin(), num.end());
                int reps = stoi(num);
                while(reps--){
                    result += str;
                }
            }
        }
        return result;
    }
};