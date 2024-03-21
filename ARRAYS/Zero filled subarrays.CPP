// 2348. Number of Zero-Filled Subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // we need to find contiguous zeroes
        int n = nums.size();
        int idx = 0;
        long long ans = 0, count = 0;
        while(idx<n){
            if(nums[idx]==0){
                count++;
            }else{
                ans += (count * (count+1))/2;
                count = 0;
            }
            idx++;
        }
        ans += (count * (count+1))/2;
        return ans;
    }
};