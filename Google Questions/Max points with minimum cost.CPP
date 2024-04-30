// 1937. Maximum Number of Points with Cost

#define ll long long
class Solution {
public:
    ll maxi(ll a, ll b){
        if(a >= b)
            return a;
        return b;
    }
    ll maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        
        // create a dp vector
        vector<ll> dp(n, 0);
        for(int j=0; j<n; j++)
            dp[j] = points[0][j];
        
        // travel row wise
        for(int i=1; i<m; i++){
            vector<ll> left(n), right(n);

            left[0] = dp[0], right[n-1] = dp[n-1];
            for(int j=1; j<n; j++)
            {
                left[j] = max(dp[j], left[j-1] - 1);
                right[n-1-j] = max(dp[n-1-j], right[n-j] - 1);
            }

            for(int j=0; j<n; j++)
                dp[j] = max(left[j], right[j]) + points[i][j];
        }   

        ll ans = dp[0];
        for(int i=1; i<n; i++)
            ans = maxi(ans, dp[i]);
        
        return ans;
    }
};