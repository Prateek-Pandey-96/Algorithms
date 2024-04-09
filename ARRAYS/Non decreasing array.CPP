// 665. Non-decreasing Array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modified = false;
        int prev = INT_MIN;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1] and !modified){
                if(prev > nums[i]){
                    nums[i] = nums[i-1];
                    modified = true;
                }else if(prev <= nums[i]){
                    nums[i-1]=prev;
                    modified = true;
                }
            }else if(nums[i]<nums[i-1] and modified){
                return false;
            }
            prev = nums[i-1];
        }
        return true;
    }
};