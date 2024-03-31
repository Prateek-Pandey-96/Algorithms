// 1968. Array With Elements Not Equal to Average of Neighbors

class Solution {
public:
    // wave array
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;

        for(int i=0; i<n-1; i++){
            if(inc and nums[i]>nums[i+1])
                swap(nums[i], nums[i+1]);
            if(!inc and nums[i]<nums[i+1])
                swap(nums[i], nums[i+1]);
            inc = !inc;
        }

        return nums;
    }
};