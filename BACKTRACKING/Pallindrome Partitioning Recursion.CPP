// 131. Palindrome Partitioning

class Solution {
public:
    bool isPallindrome(string s){
        int low = 0, high = s.length()-1;
        while(low<high){
            if(s[low++]!=s[high--])
                return false;
        }
        return true;
    }
    vector<vector<string>> Helper(string s, int idx){
        if(idx >= s.length())
        {
            return {{}};
        }

        vector<vector<string>> result;
        for(int size=1; size<=s.length()-idx; size++){
            string prev = s.substr(idx, size);
            if(isPallindrome(prev)){
                vector<vector<string>> remaining = Helper(s, idx+size);
                for(auto rem: remaining){
                    vector<string> temp = {prev};
                    for(auto str: rem)
                        temp.push_back(str);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }

    vector<vector<string>> partition(string s) {
        return Helper(s, 0);
    }
};