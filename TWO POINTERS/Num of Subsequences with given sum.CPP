// 1498. Number of Subsequences That Satisfy the Given Sum Condition

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1;
        int mod = 1e9 + 7;
        int total = 0;
        sort(nums.begin(), nums.end());
        
        vector<int> pre(n, 1);
        for(int i=1; i<n; i++)
            pre[i] = (2*pre[i-1])%mod;
        
        while(low<=high){
            int sum = nums[low] + nums[high];
            if(sum > target)
                high--;
            else{
                total = (total + pre[high-low])%mod;
                low++;
            }
        }

        return total;
    }
};