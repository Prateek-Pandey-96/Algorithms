class Solution {
public:

    int getMax(vector<int>& nums){
        int mx = nums[0];
        for(int i=1; i<nums.size(); i++)
            mx = max(mx, nums[i]);
        return mx;
    }

    bool checkPossibility(vector<int> nums, long mid){
        int n = nums.size();
        vector<long> nums_copy;
        for(int num: nums)
            nums_copy.push_back((long)num);
        for(int i=n-1; i>=1; i--){
            if(nums_copy[i]>mid){
                nums_copy[i-1] += nums_copy[i]-(long)mid;
            }
        }
        return nums_copy[0] <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        long low = 0, high = getMax(nums), ans = LONG_MAX;

        while(low <= high){
            long mid = low + (high-low)/2;
            bool possible = checkPossibility(nums, mid);
            if(possible){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return (int)ans;
    }
};