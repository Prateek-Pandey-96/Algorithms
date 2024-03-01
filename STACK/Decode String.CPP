// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        string result;
        for(auto ch: s){
            if(ch!=']')
                result.push_back(ch);
            else{
                string curr, num;
                while(result.size() and result.back() != '['){
                    curr.push_back(result.back());
                    result.pop_back();
                }
                result.pop_back();
                reverse(curr.begin(), curr.end());
                while(result.size() and result.back()>='0' and result.back()<='9'){
                    num.push_back(result.back());
                    result.pop_back();
                }
                reverse(num.begin(), num.end());
                int reps = stoi(num);
                
                while(reps--)
                    result = result + curr;
            }
        }
        return result;
    }
};