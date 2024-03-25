// 918. Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), sum = nums[0];
        int local_max = nums[0], global_max = nums[0];
        int local_min = nums[0], global_min = nums[0];

        for(int i=1; i<n; i++){
            sum += nums[i];
            local_max = max(local_max+nums[i], nums[i]);
            global_max = max(global_max, local_max);
            local_min = min(local_min+nums[i], nums[i]);
            global_min = min(global_min, local_min);
        }

        int result = max(sum-global_min, global_max);
        return result != 0? result: global_max;
    }
};