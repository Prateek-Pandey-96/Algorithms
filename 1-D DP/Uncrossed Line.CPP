// 1035. Uncrossed Lines

class Solution {
public:
    int RecursiveHelper(vector<int>& nums1, vector<int>& nums2, int x, int y, vector<vector<int>>& dp){
        if(x==nums1.size() || y==nums2.size())
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(nums1[x]==nums2[y]){
            return dp[x][y] = 1 + RecursiveHelper(nums1, nums2, x+1, y+1, dp);
        }
        return dp[x][y] = max(RecursiveHelper(nums1, nums2, x+1, y, dp), RecursiveHelper(nums1, nums2, x, y+1, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return RecursiveHelper(nums1, nums2, 0, 0, dp);
    }
};