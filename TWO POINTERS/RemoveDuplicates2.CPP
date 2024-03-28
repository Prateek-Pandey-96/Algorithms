// 80. Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        if(n<=2)
            return n;
        for(int i=0; i<n-2; i++){
            if(nums[i]==nums[i+1] and nums[i]==nums[i+2])
                continue;
            nums[idx++] = nums[i];
        }
        nums[idx++] = nums[n-2];
        nums[idx++] = nums[n-1];
        return idx;
    }
};