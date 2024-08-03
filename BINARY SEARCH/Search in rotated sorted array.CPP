// 33. Search in Rotated Sorted Array
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;

            // 0 to mid is sorted
            if(nums[mid]>=nums[0])
            {
                if(target>=nums[0] and target<nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }else{
                if(target>nums[mid] and target<=nums[n-1])
                    low = mid+1;
                else
                    high = mid-1;
            }
 
        }
        return -1;
    }
};