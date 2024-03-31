// 34. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    int getLeft(vector<int>& nums, int idx){
        int n = nums.size(), low = 0, high = idx;
        int left_idx = idx;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<nums[idx])
                low = mid+1;
            else if(nums[mid]==nums[idx])
            {
                left_idx = mid;
                high = mid-1;
            }
        }
        return left_idx;
    }
    int getRight(vector<int>& nums, int idx){
        int n = nums.size(), low = idx, high = n-1;
        int right_idx = idx;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[idx])
                high = mid-1;
            else if(nums[mid]==nums[idx])
            {
                right_idx = mid;
                low = mid+1;
            }
        }
        return right_idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target)
                high = mid-1;
            else if(nums[mid]<target)
                low = mid+1;
            else{
                int l = getLeft(nums, mid);
                int r = getRight(nums, mid);
                return {l, r};
            }
        }

        return {-1, -1};
    }
};