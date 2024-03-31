// 162. Find Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mid > 0 and nums[mid-1] > nums[mid])
                high = mid-1;
            else if(mid < n-1 and nums[mid+1] > nums[mid])
                low = mid+1;
            else
                return mid;
        }
        return -1;
    }
};