class Solution {
public:
    bool isPallindrome(string s){
        int low = 0, high = s.length()-1;
        while(low<high){
            if(s[low]==s[high]){
                low++;
                high--;
            }else
                return false;
        }
        return true;
    }

    vector<vector<string>> dfs(string s, int idx, unordered_map<int, vector<vector<string>>>& dp){
        if(idx==s.length())
            return {{}};
        
        if(dp.contains(idx))
            return dp[idx];
        
        vector<vector<string>> result;
        for(int len=1; len<=s.length()-idx; len++){
            string prefix = s.substr(idx, len);
            if(isPallindrome(prefix)){
                vector<vector<string>> partition_suffixes = dfs(s, idx+len, dp);
                for(vector<string> partition_suffix: partition_suffixes)
                {
                    vector<string> temp = {prefix};
                    for(string suffix: partition_suffix)
                        temp.push_back(suffix);
                    result.push_back(temp);
                }
            }
        }
        return dp[idx] = result;
    }

    vector<vector<string>> partition(string s) {
        unordered_map<int, vector<vector<string>>> dp;
        return dfs(s, 0, dp);
    }
};

// Better backtracking solution
class Solution {
public:
    bool isPallindrome(string temp){
        int low = 0, high = temp.length()-1;
        while(low<=high){
            if(temp[low]!=temp[high])
                return false;
            low++,high--;
        }
        return true;
    }
    void pallindromeGenerator(vector<vector<string>>& result, vector<string>& temp, string A){
        if(A.length()==0)
        {
            result.push_back(temp);
            return;
        }

        for(int i=0;i<A.length();i++){
            string pre = A.substr(0, i+1);
            string remaining = A.substr(i+1);
            if(isPallindrome(pre)){
                temp.push_back(pre);
                pallindromeGenerator(result, temp, remaining);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        pallindromeGenerator(result, temp, s);
        return result;
    }
};