// 523. Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if the remainder repeats we have found our subarray
        // take care of the length too
        int n = nums.size();
        unordered_map<int, int> hashmap;
        int sum = 0;
        hashmap[0] = -1;

        for(int i=0; i<n; i++){
            sum += nums[i];

            if(hashmap.contains(sum%k) and i-hashmap[sum%k]>=2)
                return true;
            
            // we want to store the min idx that had the remainder
            if(!hashmap.contains(sum%k))
                hashmap[sum%k] = i;
        } 

        return false;
    }
};