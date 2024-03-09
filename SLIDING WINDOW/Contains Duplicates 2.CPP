// 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        if(n==1)
            return false;
        
        for(int i=0; i<=k and i<n; i++)
        {
            if(hashmap.contains(nums[i]))
                return true;
            hashmap[nums[i]]++;
        }

        for(int i=k+1; i<n; i++){

            if(hashmap.contains(nums[i-k-1])){
                hashmap[nums[i-k-1]]--;
                if(hashmap[nums[i-k-1]]==0)
                    hashmap.erase(nums[i-k-1]);
            }

            if(hashmap.contains(nums[i]))
                return true;
            hashmap[nums[i]]++;
        }

        return false;
    }
};