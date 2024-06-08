// 523. Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        hashmap[0] = -1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(hashmap.contains(sum%k) and i-hashmap[sum%k]>=2){
                return true;
            }

            if(!hashmap.contains(sum%k))
                hashmap[sum%k]=i;
        }
        return false;
    }
};