// 2140. Solving Questions With Brainpower

class Solution {
public:
    long long recursiveHelper(vector<vector<int>>& questions, int idx, vector<long long>& dp){
        if(idx >= questions.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        long long include = questions[idx][0] + recursiveHelper(questions, idx+questions[idx][1]+1, dp);
        long long exclude = recursiveHelper(questions, idx+1, dp);

        return dp[idx] = include >= exclude? include: exclude;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        /*
            Inclusion-Exclusion At each index we can either solve it or not solve it
            If we solve it we can't solve brainpower[i] further questions
        */
        int n = questions.size();
        vector<long long> dp(n, -1);
        long long helper = recursiveHelper(questions, 0, dp);
        return helper;
    }
};