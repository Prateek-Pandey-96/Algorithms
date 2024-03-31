// 153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1;
        if(nums[low]<nums[high] || n==1)
            return nums[0];

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= nums[0])
                low = mid+1;
            else
                high = mid;

            if(nums[mid] < nums[(mid-1+n)%n] and nums[mid] < nums[(mid+1)%n])
                return nums[mid];

        }
        return -1;
    }
};