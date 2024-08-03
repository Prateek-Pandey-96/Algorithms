// 410. Split Array Largest Sum

class Solution {
public:
    pair<int, int> getRange(vector<int>& nums){
        int sum = nums[0], mx = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum += nums[i];
            mx = max(mx, nums[i]);
        }
        return {mx, sum};
    }
    int Helper(vector<int>& nums, int limit){
        int subarrays = 1;
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum += nums[i];
            if(sum > limit){
                sum = nums[i];
                subarrays++;
            }
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        auto [l, r] = getRange(nums);
        int min_largest_sum;
        while(l<=r){
            int mid = l + (r-l)/2;
            int subarrays_formed = Helper(nums, mid);
            if(subarrays_formed > k){
                l = mid+1;
            }else{
                min_largest_sum = mid;
                r = mid-1;
            }
        }
        return min_largest_sum;
    }
};