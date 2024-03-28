// 15. 3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while(i<n-2){
            int j=i+1, k=n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(j<k and nums[k]==nums[k+1]) k--;
                }else if(sum>0)
                    k--;
                else 
                    j++;
            }
            i++;
            while(i<n and nums[i]==nums[i-1]) i++;
        }
        return result;
    }
};