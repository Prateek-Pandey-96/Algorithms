// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, subarrays = 0;
        unordered_map<int, int> sum_idx;
        sum_idx[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            
            if(sum_idx.contains(sum - k))
                subarrays+=sum_idx[sum-k];
            
            sum_idx[sum]++;
        }

        return subarrays;
    }
};