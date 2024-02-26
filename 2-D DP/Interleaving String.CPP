// 97. Interleaving String

class Solution {
public:
    bool isPossible(string s1, string s2, string s3, int idx1, int idx2, vector<vector<int>>& dp){
        // all three exhausted
        if(idx1 == s1.length() and idx2 == s2.length() and idx1+idx2 == s3.length())
            return true;
        // memoization
        if (dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        // atleast s1 or s2 left
        if (idx1+idx2 == s3.length() and (idx1 < s1.length() or idx2 < s2.length()))
            return dp[idx1][idx2] = false;
        // if both first characters match
        if (idx1 < s1.length() and idx2 < s2.length() and s1[idx1] == s3[idx1+idx2] and s2[idx2] == s3[idx1+idx2])
            return dp[idx1][idx2] = isPossible(s1, s2, s3, idx1+1, idx2, dp)|| isPossible(s1, s2, s3, idx1, idx2+1, dp);
        // if s1 first character match
        if (idx1 < s1.length() and s1[idx1] == s3[idx1+idx2])
            return dp[idx1][idx2] = isPossible(s1, s2, s3, idx1+1, idx2, dp);
        // if s2 first character match
        if (idx2 < s2.length() and s2[idx2] == s3[idx1+idx2])
            return dp[idx1][idx2] = isPossible(s1, s2, s3, idx1, idx2+1, dp);

        return dp[idx1][idx2] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        /*Each character in s3 will either come from s1 or s2*/
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return isPossible(s1, s2, s3, 0, 0, dp);
    }
};