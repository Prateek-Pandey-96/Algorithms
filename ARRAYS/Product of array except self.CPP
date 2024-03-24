// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // at each idx we need prefix and suffix product
        int n = nums.size();
        vector<int> result(n, 1);
        int left = 1, right = 1;
        
        for(int i=0; i<n; i++){
            result[i] = left*result[i];
            left = left*nums[i];
            
            result[n-1-i] = right*result[n-i-1];
            right = right*nums[n-i-1];
        }

        return result;
    }
};