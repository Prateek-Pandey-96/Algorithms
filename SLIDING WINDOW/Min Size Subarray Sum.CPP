// 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, n = nums.size();
        int i=0, j=0, min_len = INT_MAX;

        while(j < n){
            sum += nums[j];

            while(sum >= target){
                min_len = min(min_len, j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return min_len!=INT_MAX? min_len: 0;
    }
};