//22. Generate Parentheses

class Solution {
public:
    void recursive_helper(int open, int close, int n, string curr, vector<string>& result){
        
        if(open + close == 2*n){
            result.push_back(curr);
            return;
        }

        if(open < n){
            if(open > close)
            {
                recursive_helper(open, close+1, n, curr+")", result);
                recursive_helper(open+1, close, n, curr+"(", result);
            }
            else if (open == close)
                recursive_helper(open+1, close, n, curr+"(", result);
        }else if(open == n){
            recursive_helper(open, close+1, n, curr+")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> result;
        string curr = "";
        recursive_helper(open, close, n, curr, result);
        return result;
    }
};