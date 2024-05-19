// 3068. Find the Maximum Sum of Node Values

class Solution {
public:
    static bool compare(long long a, long long b){
        return b<a;
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0, sum = 0;
        int n = nums.size();
        vector<long long> delta(n);
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            delta[i] = (nums[i] ^ k) - nums[i];
        }
        sort(delta.begin(), delta.end(), compare);

        for(int i=0; i<n-1; i+=2)
        {
            long long temp_sum = delta[i] + delta[i+1];
            if(temp_sum > 0)
                sum += temp_sum;
        }

        return sum;
    }
};