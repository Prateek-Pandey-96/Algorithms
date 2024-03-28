class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(), outer = 0;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while(outer<n-3){
            int inner = outer+1;
            while(inner<n-2){
                int j=inner+1, k=n-1;
                while(j < k){
                    long sum = (long)nums[outer] + (long)nums[inner] + (long)nums[j] + (long)nums[k];
                    if(sum==target){
                        result.push_back({nums[outer], nums[inner], nums[j], nums[k]});
                        j++, k--;
                        while(j<k and nums[j]==nums[j-1]) j++;
                        while(j<k and nums[k]==nums[k+1]) k--;
                    }else if(sum>target)
                        k--;
                    else 
                        j++;
                }
                inner++;
                while(inner < n and nums[inner]==nums[inner-1]) inner++;
            }  
            outer++;
            while(outer < n and nums[outer]==nums[outer-1]) outer++;
        }
        return result;
    }
};